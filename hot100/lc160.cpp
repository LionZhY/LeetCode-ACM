#include <iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};



ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
    ListNode* curA = headA;
    ListNode* curB = headB;

    while (curA != curB)
    {
        curA = (curA != nullptr) ? curA->next : headB;
        curB = (curB != nullptr) ? curB->next : headA;
    }


    return curA;
}



int main()
{
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* a3 = new ListNode(2);
    ListNode* a4 = new ListNode(8);
    ListNode* a5 = new ListNode(6);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(7);
    b1->next = b2;
    b2->next = a4;

    ListNode* result = getIntersectionNode(a1, b1);

    if (result) cout << result->val << endl;
    else    cout << "null" << endl;


    return  0;

}