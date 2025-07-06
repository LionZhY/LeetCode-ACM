#include <iostream>
using namespace std;

// 19 删除链表的倒数第n个节点
// 时间复杂度：O(N) N为链表长度
// 空间复杂度：O(1)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* slow = dummyHead;
    ListNode* fast = dummyHead;

    // fast 先走 n + 1 步
    while (n-- && fast)
    {
        fast = fast->next;
    }
    fast = fast->next;
    // for (int i = 0; i <= n; ++i) {
    //    fast = fast->next;
    // }

    // slow 和 fast 一起移动
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // 删除 slow->next
    ListNode* tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;

    return dummyHead->next;
}


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;// 删除倒数第2个

    ListNode* result = removeNthFromEnd(head, n);

    // 输出
    while (result)
    {
        cout << result->val;
        if (result->next)   cout << "->";
        result = result->next;
    }
    cout << endl;


    return 0;
}