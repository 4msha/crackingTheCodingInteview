#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

void deleteMid(ListNode *ptr)
{
    ListNode *temp = ptr;

    while (temp->next != NULL)
    {
        temp->val = temp->next->val;
        if (temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp = temp->next;
        }
    }
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
    cout << "Before Removal\n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    ListNode *kthNode{head};

    while (--k)
    {
        kthNode = kthNode->next;
    }

    deleteMid(kthNode);

    tempPtr = head;
    cout << "After Removal\n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}