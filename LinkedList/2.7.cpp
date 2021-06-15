#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

ListNode *sameIndex(ListNode *head, ListNode *head2)
{
    set<ListNode *> mp;

    ListNode *temp{head};

    while (temp != NULL)
    {
        mp.insert(temp);
        temp = temp->next;
    }

    temp = head2;

    while (temp != NULL)
    {
        if (mp.find(temp) != mp.end())
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
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
    cout << " List 1 \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    tempPtr = head2;
    cout << " List 2 \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    int randomIndex = rand() % n;
    tempPtr = head;

    while (--randomIndex)
    {
        tempPtr = tempPtr->next;
    }

    ListNode *head2Last{head2};

    while (head2Last->next != NULL)
    {
        head2Last = head2Last->next;
    }

    head2Last->next = tempPtr;

    // ListNode *ans = sameIndex(head, head2);

    // cout << ans->val << "  " << tempPtr->val << endl;
    return 0;
}