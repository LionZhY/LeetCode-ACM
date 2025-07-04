#include <iostream>
using namespace std;

// 21 合并两个有序链表
// 时间复杂度：O(n + m)
// 空间复杂度：O(1)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 合并
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;

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

    cur->next = (list1 != nullptr) ? list1 : list2;

    return dummyHead->next;
}


int main()
{
    // 构建链表 list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // 构建链表 list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    // 合并链表
    ListNode* mergeNode = mergeTwoLists(list1, list2);

    // 打印
    while (mergeNode)
    {
        cout << mergeNode->val << " ";
        mergeNode = mergeNode->next;
    }
    cout << endl;

    return 0;
}
