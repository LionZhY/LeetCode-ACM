#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    
    ListNode* curA = headA;
    ListNode* curB = headB;

    // 求链表A和链表B的长度
    int lenA = 0, lenB = 0;
    while (curA != nullptr)
    {
        lenA++;
        curA = curA->next;
    }
    while (curB != nullptr)
    {
        lenB++;
        curB = curB->next;
    }

    // cur再移回头节点
    curA = headA;
    curB = headB;

    // 让curA称为较长链表的头，lenA为其长度
    if (lenB > lenA)
    {
        swap(lenA, lenB);
        swap(curA, curB);
    }

    // 末尾对齐，移动curA到与curB相对应的位置
    int gap = lenA - lenB;
    while (gap--)
    {
        curA = curA->next;
    }

    // 然后 curA curB 同时向后移动，遇到相同节点即相交节点
    while (curA != nullptr)
    {
        if (curA == curB)   return curA; // 注意是指针相等，不是数值相等！！！

        curA = curA->next;
        curB = curB->next;
    }

    return nullptr; // 无相交节点
        
}


int main()
{
    // 构建链表 A: 4 -> 1 -> [8 -> 4 -> 5]
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* a3 = new ListNode(8);
    ListNode* a4 = new ListNode(4);
    ListNode* a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;


    // 构建链表 B: 5 -> 0 -> 1 -> [8 -> 4 -> 5]
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(0);
    ListNode* b3 = new ListNode(1);
    b1->next = b2;
    b2->next = b3;
    b3->next = a3; // 直接连在A中的节点 与链表 A 相交于节点值 8

    ListNode* result = getIntersectionNode(a1, b1);

    if (result) cout << result->val << endl; // 输出相交节点值
    else        cout << "null" << endl;

    
    return 0;
}