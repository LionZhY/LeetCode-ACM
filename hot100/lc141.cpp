#include <iostream>
using namespace std;

// 141 环形链表 （快慢指针相遇）
// 时间复杂度: O(n)
// 空间复杂度: O(1)

// 定义链表节点结构
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断链表是否有环
bool hasCycle(ListNode* head) 
{
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) 
    {
        slow = slow->next;       // slow 走一步
        fast = fast->next->next; // fast 走两步
        if (slow == fast) return true; // 快慢指针相遇说明有环
    }

    return false;
}


int main() {
    // 构建链表 3 -> 2 -> 0 -> -4
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;  // 制造环，使得 -4 指向 2，形成环

    if (hasCycle(n1)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}