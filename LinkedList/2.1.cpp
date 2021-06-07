#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

//buffer array available to use
ListNode *removeDuplicates(ListNode *head)
{
    set<int> st;
    st.insert(head->val);

    ListNode *temp = head;

    while (temp->next != NULL)
    {
        if (st.find(temp->next->val) != st.end())
        {
            ListNode *t = temp->next;
            temp->next = temp->next->next;
            free(t);
        }
        else
        {
            st.insert(temp->next->val);
            temp = temp->next;
        }
    }

    return head;
}

//buffer not available

ListNode *removeDupsBuffer(ListNode *head)
{
    ListNode *temp = head;

    while (temp != NULL)
    {
        ListNode *ptr = temp;
        while (ptr->next != NULL)
        {
            if (ptr->next->val == temp->val)
            {
                ListNode *t = ptr->next;
                ptr->next = ptr->next->next;
                free(t);
            }
            else
            {
                ptr = ptr->next;
            }
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    int n, temp;
    cin >> n;

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

    ListNode *ud = removeDupsBuffer(head);

    tempPtr = head;
    cout << "After Removal\n";

    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;
}