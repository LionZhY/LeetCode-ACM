#include <iostream>
#include <vector>
using namespace std;

// 23 合并k个有序链表
// 最小堆：
//      时间复杂度：O(Llogm)，其中 m 为 lists 的长度，L 为所有链表的长度之和。
//      空间复杂度：O(m)。堆中至多有 m 个元素
// 分治递归：
//      时间复杂度：O(Llogm)，其中 m 为 lists 的长度，L 为所有链表的长度之和。
//      空间复杂度：O(logm)。递归深度为 O(logm)，需要 O(logm) 的栈空间。


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 21 合并两个有序链表(升序)
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
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

    cur->next = list1 ? list1 :  list2;
    return dummy->next;
}

// 合并从 lists[i] 到 lists[j-1] 的链表
ListNode* mergeRange(vector<ListNode*>& lists, int i, int j) 
{
    int m = j - i; // [i, j)
    if (m == 0) return nullptr;  // 输入的 lists 可能是空的
    if (m == 1) return lists[i]; // 无需合并，直接返回
    
    auto left  = mergeRange(lists, i, i + m / 2); // 合并左半部分
    auto right = mergeRange(lists, i + m / 2, j); // 合并右半部分

    return mergeTwoLists(left, right); // 最后把左半和右半合并
}


// 合并k个升序链表
ListNode* mergeKLists(vector<ListNode*>& lists) 
{
    return mergeRange(lists, 0, lists.size()); // 递归合并
}


int main() 
{
    // 构建三个有序链表
    ListNode* l1 = new ListNode(1); // 1->4->5
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1); // 1->3->4
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2); // 2->6
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* merged = mergeKLists(lists); // 合并

    while (merged)
    {
        cout << merged->val;
        if (merged->next)   cout << "->";
        merged = merged->next;
    }
    cout << endl;

    return 0;
}