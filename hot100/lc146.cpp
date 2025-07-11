#include <iostream>
#include <unordered_map>
using namespace std;

// 146 LRU缓存
// 时间复杂度：所有操作均为 O(1)
// 空间复杂度：O(min(p,capacity))，其中 p 为 put 的调用次数


// 双向链表结构
class Node
{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity; // 容量
    unordered_map<int, Node*> key_to_node; // <key, node>
    Node* dummy;


    // 删除一个节点（抽出一本书）
    void removeNode(Node* x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
    }

    // 插入节点到链表头部（dummy后面）（把一本书放在最上面）
    void push_front(Node* x)
    {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    // 获取 key 节点返回，并移动到头部（抽出一本书放在最上面）
    Node* get_node_push(int key)
    {
        auto it = key_to_node.find(key);

        if (it == key_to_node.end())   return nullptr;

        Node* node = it->second;
        removeNode(node);
        push_front(node);
        return node;
    }


public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node()) // 初始化
    {
        dummy->prev = dummy;
        dummy->next = dummy;
    }


    // get() 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 
    int get(int key)
    {
        Node* node = get_node_push(key);
        return node ? node->value : -1;
    }


    // 如果关键字 key 已经存在，则变更其数据值 value 
    // 如果不存在，则向缓存中插入该组 key-value 
    // 如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字
    void put(int key, int value)
    {
        Node* node = get_node_push(key);

        // 节点存在
        if (node)
        {
            node->value = value;
            return;
        }

        // 节点不存在，创建新节点插入头部
        Node* new_node = new Node(key, value);
        push_front(new_node);
        key_to_node[key] = new_node;

        // 节点插入后，容量爆了，移除最后节点
        if (key_to_node.size() > capacity)
        {
            Node* back_node = dummy->prev;
            key_to_node.erase(back_node->key); // 在map删除
            removeNode(back_node);             // 在链表删除

            delete back_node; // 释放内存
        }
    }

};


int main()
{
    LRUCache lru(2); // capacity = 2

    lru.put(1, 1); // {1=1}
    lru.put(2, 2); // {1=1, 2=2}

    cout << "get(1)" << lru.get(1) << endl; // 输出1  {2=2，1=1}

    lru.put(3, 3); // 超出capacity，淘汰key=2  {1=1，3=3}

    cout << "get(2)" << lru.get(2) << endl; // 输出-1

    lru.put(4, 4); // 超出capacity，淘汰key=1  {3=3, 4=4}
    
    cout << "get(1)" << lru.get(1) << endl; // 输出-1
    cout << "get(3)" << lru.get(3) << endl; // 输出 3
    cout << "get(4)" << lru.get(4) << endl; // 输出 4


    return 0;
}




