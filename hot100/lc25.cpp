#include <iostream>
using namespace std;

// 25 k个一组翻转链表
// 时间复杂度：O(n)，其中 n 为链表节点个数。
// 空间复杂度：O(1)，仅用到若干额外变量。

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode* reverseKGroup(ListNode* head, int k)
{
    // 统计链表长度
    int n = 0;
    ListNode* node = head;
    while (node)
    {
        n++;
        node = node->next;
    }

    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;

    ListNode* p0 = dummyHead; // p0 作为 [下一组要反转的k个节点的] 上一个节点
    ListNode* pre = nullptr;
    ListNode* cur = head;

    while (n >= k)
    {
        // 反转当前这k个节点
        for (int i = 0; i < k; i++)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }

        // 连接前后
        ListNode* nxt = p0->next;
        p0->next->next = cur;
        p0->next = pre;
        p0 = nxt; // 更新p0

        // 更新 n
        n -= k;

        pre = nullptr; // 可以不重置，重置好理解一些
    
    }

    return dummyHead->next;
}





int main()
{
    // 构建链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    // 执行K个一组翻转
    ListNode* newHead = reverseKGroup(head, k);

    // 输出结果链表
    while (newHead) {
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;


    return 0;
}