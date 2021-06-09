#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
};

bool checkPalindrome(ListNode *head)
{
    ListNode *temp{head};
    string ans;

    while (temp != NULL)
    {
        ans += to_string(temp->val);
        temp = temp->next;
    }

    int i, j;
    int n = ans.length();

    if (n & 1)
    {
        i = n / 2;
        j = n / 2;
    }
    else
    {
        i = n / 2 - 1;
        j = n / 2;
    }

    while (i > -1 && j < n)
    {
        if (ans[i] != ans[j])
        {
            return false;
        }
        i--;
        j++;
    }

    return true;
}

int main()
{
    int n, temp, k;
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
    cout << "Before List 1 \n";
    while (tempPtr != NULL)
    {
        cout << tempPtr->val << "  ";
        tempPtr = tempPtr->next;
    }
    cout << endl;

    bool isPalindrome = checkPalindrome(head);

    if (isPalindrome)
    {
        cout << "Its a palindrome\n";
    }
    else
    {
        cout << "Its not a palindrome\n";
    }
}