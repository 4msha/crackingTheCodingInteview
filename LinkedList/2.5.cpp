#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *sum2List(ListNode *ptr1, ListNode *ptr2)
{
    ListNode *head;
    int carry{0};
    ListNode *temp1{ptr1}, *temp2{ptr2}, *temp;

    while (temp1 != NULL && temp2 != NULL)
    {
        int s = temp1->val + temp2->val + carry;
        carry = s / 10;
        s = s % 10;

        if (head == NULL)
        {
            head = new ListNode();
            head->val = s;
            temp = head;
        }
        else
        {
            ListNode *x = new ListNode();
            x->val = s;
            temp->next = x;
            temp = x;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
        cout << temp->val << endl;
    }

    cout << temp1->val << "  " << temp->val << endl;

    if (temp1 != NULL)
    {
        ListNode *x = new ListNode();
        int s = temp1->val + carry;
        carry = s / 10;
        x->val = s % 10;
        temp->next = x;
        temp = x;
        temp1 = temp1->next;
        cout << temp->val << endl;
    }

    if (temp2 != NULL)
    {
        ListNode *x = new ListNode();
        int s = temp2->val + carry;
        carry = s / 10;
        x->val = s % 10;
        temp->next = x;
        temp = x;
        temp2 = temp2->next;
        cout << temp->val << endl;
    }

    temp = head;
    while (temp != NULL)
    {
        cout << temp->val << "  ";
        temp = temp->next;
    }

    return head;
}

int main()
{
    int n, temp, k;
    cin >> n >> k;

    cin >> temp;
    ListNode *head = new ListNode();
    ListNode *head2 = new ListNode();
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

    cin >> temp;
    head2->val = temp;
    tempPtr = head2;
    while (--k)
    {
        cin >> temp;
        ListNode *x = new ListNode();
        x->val = temp;
        tempPtr->next = x;
        tempPtr = x;
    }
    tempPtr = head;
    cout << "Before List 1 \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    tempPtr = head2;
    cout << "Before List 2 \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    ListNode *newHead = sum2List(head, head2);

    cout << " New List \n";
    tempPtr = newHead;
    // while (tempPtr != NULL)
    // {
    //     cout << tempPtr->val << "  ";
    //     tempPtr = tempPtr->next;
    // }
    // cout << endl;
}