#include <iostream>
using namespace std;


// 142 环形链表找入口
// 时间复杂度: O(n)
// 空间复杂度: O(1)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


// 检测环并返回入环的起始节点
ListNode* detectCycle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;

    // 1 判断是否有环
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        // 2 有环，找入口
        if (slow == fast)
        {
            ListNode* index1 = slow; // 相遇点开始
            ListNode* index2 = head; // 头节点开始
            while(index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
            }
            return index2; // 环入口
        }
    }

    return nullptr; // 无环
}


int main()
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2; // 形成环，入口是n2

    ListNode* cycleNode = detectCycle(n1);
    if (cycleNode)
    {
        cout << "Cycle entry node value: " << cycleNode->val << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }
    

    return 0;
}

