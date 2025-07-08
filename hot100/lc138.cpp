#include <iostream>
#include <unordered_map>
using namespace std;

// 链表节点定义
struct Node {
    int val;
    Node* next;
    Node* random; // random_index：随机指针指向的节点索引

    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};


Node* copyRandomList(Node* head)
{
    if (head == nullptr)    return nullptr;

    // umap <原节点，新节点>
    unordered_map<Node*, Node*> umap;
    Node* cur = head;
    while (cur)
    {
        umap[cur] = new Node(cur->val);
        cur = cur->next;
    }

    // 复制 next 和 random 指针
    cur = head;
    while (cur)
    {
        umap[cur]->next = umap[cur->next];
        umap[cur]->random = umap[cur->random];
        cur = cur->next;
    }

    return umap[head];
}


int main()
{
    // 构建链表: 1 -> 2 -> 3
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    node1->next = node2;
    node2->next = node3;

    // 设置 random 指针
    node1->random = node3; // 1->random->3
    node2->random = node1; // 2->random->1
    node3->random = node2; // 3->random->2

    Node* copiedHead = copyRandomList(node1);


    // 打印结果（val 和 random->val）
    Node* p = copiedHead;
    while (p) 
    {
        cout << "val: " << p->val;
        if (p->random)
        {
            cout << ", random: " << p->random->val << endl;
        }
        else
        {
            cout << ", random: NULL" << endl;
        }
        p = p->next;
    }

    return 0;
}


