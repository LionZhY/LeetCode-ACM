#include <iostream>
using namespace std;

// 24 两两交换链表中的节点
// 时间复杂度：O(N) N为链表长度
// 空间复杂度：O(1)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* swapPairs(ListNode* head)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* cur = dummyHead;

    while (cur->next && cur->next->next)
    {
        ListNode* tmp = cur->next;
        ListNode* tmp1 = cur->next->next->next;

        // 交换cur后的两个节点
        cur->next = cur->next->next;
        cur->next->next = tmp;
        cur->next->next->next = tmp1;

        // cur 后移两个位置
        cur = cur->next->next;
    }

    return dummyHead->next;
}


int main()
{
    // 构建链表: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* newHead = swapPairs(head);

    while (newHead)
    {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;

    return 0;
}