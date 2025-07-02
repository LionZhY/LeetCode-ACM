#include <cstddef>
#include <iostream>
using namespace std;

// 234 回文链表：中间节点 + 反转
// 时间复杂度: O(n)
// 空间复杂度: O(1)

// 链表结构定义
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {};
};


// 876 找中间节点
ListNode* middleNode(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// 206 反转链表
ListNode* reverseList(ListNode* head)
{
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


// 回文
bool isPalindrome(ListNode* head)
{
    ListNode* mid = middleNode(head);
    ListNode* head2 = reverseList(mid);

    while(head2)
    {
        if (head->val != head2->val)    return false;
        head = head->next;
        head2 = head2->next;
    }

    return true;
}



int main()
{
    int n;
    cin >> n; // 链表长度
    if (n <= 0)
    {
        cout << "false" << endl;
        return 0;
    }

    // 构建链表
    int x;
    cin >> x;
    ListNode* head = new ListNode(x);
    ListNode* cur = head;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        cur->next = new ListNode(x);
        cur = cur->next;
    }

    bool result = isPalindrome(head);
    cout << (result ? "true" : "false") << endl;

    
    return 0;
}
