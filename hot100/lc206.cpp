#include <iostream>
using namespace std;

// 链表结构
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 反转链表
ListNode* reverseList(ListNode* head)
{
    // 双指针
    ListNode* tmp;
    ListNode* cur = head;
    ListNode* pre = nullptr;

    while (cur)
    {
        tmp = cur->next;
        cur->next = pre;

        pre = cur;
        cur = tmp;
    }

    return pre;
}


int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* result = reverseList(head);

    while (result)
    {
        cout << result->val << endl;
        result = result->next;
    }


    return 0;

}
