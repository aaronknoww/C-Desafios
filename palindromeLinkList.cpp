//Definition for singly-linked list.
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
int c;
    ListNode* reverseList(ListNode* head)
    {
      c = 0;
        if(head ==  nullptr)
            return head;
        if(head->next == nullptr)
            return head;
        
        
        ListNode* sig = head->next;
        ListNode* ant = nullptr;
        ListNode * cur = head;
        
        while(sig != nullptr)
        {
            cur->next = ant;
            ant = cur;
            cur = sig;
            sig = sig->next;
            c++;            
        }
        cur->next = ant;
        return cur;
        
    }
public:
    bool isPalindrome(ListNode* head)
    {
        if(head->next == nullptr)
            return true;
        
        if(head->next->next == nullptr)
            if(head->val == head->next->val)
                return true;
            else
                return false;
        int cont = 0;
        ListNode* half = head;
        ListNode* fast = head;

        while(fast)
        {
            half = half->next;
            fast = (fast->next && fast->next->next)?fast->next->next:nullptr;
            cont++;
        }

        half = reverseList(half);
        fast = head;

        for(int i = 0; i<c; i++)
        {
            if(half->val != fast->val)
                return false;
            half = half->next;
            fast = fast->next;
        }
        return true;

    }
};
int main()
{
      //[1,1,2,1]
    ListNode* head=nullptr;
    ListNode n0(1), n1(1), n2(2), n3(1);
    head = &n0;
    head->next = &n1;
    head->next->next = &n2;
    //head->next->next->next = &n3;

    Solution ob;
    ob.isPalindrome(head);
    return 0;
}