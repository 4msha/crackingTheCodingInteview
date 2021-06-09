#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *llPartition(ListNode *head, int x)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        if (temp->val < x)
        {
            ListNode *ptr;
            ptr = new ListNode();
            ptr->val = temp->val;
            ptr->next = head;
            head = ptr;
            if (temp->next != NULL)
            {
                temp->val = temp->next->val;
                ptr = temp->next;
                temp->next = temp->next->next;
                free(ptr);
            }
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
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
    cout << "Before \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    ListNode *newHead = llPartition(head, k);

    cout << " After\n";
    tempPtr = newHead;
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}