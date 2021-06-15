#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

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
}