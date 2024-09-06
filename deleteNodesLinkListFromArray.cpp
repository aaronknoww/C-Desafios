// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class Solution {
public:
    Node* modifiedList(vector<int>& nums, Node* head) {
        unordered_set<int> set(nums.begin(), nums.end());
      if(head->next == nullptr)
      {
          if(set.find(head->val) != set.end())
                return head = nullptr;
          return head;
      }
      Node * first = head;
      Node * last = head;
      bool flag = false;
      while (last && set.find(last->val) != set.end())
      {
          last = last->next;
          flag = true;
      }
      if(flag)
      {            
            head = last;
            first = head;
            last = (last)?last->next:nullptr;           

      }
       else
      {
            last = (last)?last->next:nullptr;
      }

      flag = false;
      while (last)
      {
            while (last && set.find(last->val) != set.end())
            {
                  //if enter here at least one element have to be erased.
                  last = last->next;
                  flag  = true;
            }
            if(flag)
            {
                  first->next = last;
                  first = last;
            }
            else
            {
                  first = first -> next;
            }
            last = (last) ? last->next : nullptr;
            flag = false;
            /* code */
      }
      return head;
        
    }
};
int main()
{
      vector<int> arr = {1,2,6};

      Node* p = new Node(9,new Node(6, new Node(9)));
      //Node nod(8);
      //p = &nod;
   
    Solution ob;
    ob.modifiedList(arr, p);
    return 0;
}