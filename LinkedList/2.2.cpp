#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

//using recursion
ListNode *findKthElement(ListNode *head, int &i, int k)
{
    if (head == NULL)
        return NULL;

    ListNode *x = findKthElement(head->next, i, k);
    i += 1;
    if (i == k)
    {
        return head;
    }
    return x;
}

//using iteration
ListNode *findKthElementIter(ListNode *head, int k)
{
    ListNode *ptr1{head}, *ptr2{head};
    while (k--)
    {
        ptr1 = ptr1->next;
    }

    while (ptr1 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2;
}

int main()
{
    int n, temp, k;
    cin >> n >> k;

    cin >> temp;
    ListNode *head = new ListNode();
    head->val = temp;
    ListNode *tempPtr = head;

    while (--n)
    {
        cin >> temp;
        ListNode *x = new ListNode();
        x->val = temp;
        tempPtr->next = x;
        tempPtr = x;
    }

    tempPtr = head;
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    int i{0};

    ListNode *kthElement = findKthElementIter(head, k);

    cout << " Kth element from the end is " << kthElement->val << endl;
    return 0;
}