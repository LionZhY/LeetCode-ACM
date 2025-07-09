#include <iostream>
using namespace std;

// 148 排序链表
// 时间复杂度：O(nlogn)
// 空间复杂度：O(logn)


struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};



// 找链表的中间节点并断开，返回后一半的头节点
ListNode* middleNode(ListNode* head) 
{
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = nullptr; // 断开前半部分
    return mid;
}

// 合并两个有序链表
ListNode* mergerTwoLists(ListNode* list1, ListNode* list2) 
{
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (list1 && list2) 
    {
        if (list1->val < list2->val) 
        {
            cur->next = list1;
            list1 = list1->next;
        } 
        else 
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }

    cur->next = list1 ? list1 : list2;
    return dummy->next;
}


// 排序链表
ListNode* sortList(ListNode* head) 
{
    if (!head || !head->next) return head;

    ListNode* head2 = middleNode(head);
    head = sortList(head);
    head2 = sortList(head2);

    return mergerTwoLists(head, head2);
}


int main() 
{
    // 构建链表：4 -> 2 -> 1 -> 3
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    // 排序
    head = sortList(head);

    // 输出结果
    while (head) 
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
