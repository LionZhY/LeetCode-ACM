#include <iostream>
using namespace std;

// 2 两数之和
// 时间复杂度：O(m + n)
// 空间复杂度：O(1)

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummyHead = new ListNode(0);
    ListNode* node = dummyHead;

    int carrier = 0;
    while (l1 || l2 || carrier)
    {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carrier;

        node->next = new ListNode(sum % 10);
        carrier = sum / 10;

        node = node->next;
        if (l1)     l1 = l1->next;
        if (l2)     l2 = l2->next;
    }

    return dummyHead->next;
}


int main()
{
    // 构建链表 l1: 2 -> 4 -> 3 （表示数字342）注意顺序
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 构建链表 l2: 5 -> 6 -> 4 （表示数字465）
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 相加 
    //      3 <- 4 <- 2 
    // +    4 <- 6 <- 5
    // =    8 <- 0 <- 7
    ListNode* result = addTwoNumbers(l1, l2);

    // 输出
    while (result)
    {
        cout << result->val;
        if (result->next)   cout << "->";
        result = result->next;
    }

    cout << endl;


    return  0;
}