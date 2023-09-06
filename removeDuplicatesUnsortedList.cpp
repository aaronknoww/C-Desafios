//{ Driver Code Starts

// TERMINADO Y PASO LOS 1120 CASOS DE GFG

#include <bits/stdc++.h>
using namespace std;

struct Node
{
      int data;
      struct Node *next;
      Node(int x)
      {
            data = x;
            next = NULL;
      }
};

void print(Node *root)
{
      Node *temp = root;
      while (temp != NULL)
      {
            cout << temp->data << " ";
            temp = temp->next;
      }
}

// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
      // Function to remove duplicates from unsorted linked list.
      Node *removeDuplicates(Node *head)
      {
            if (head->next == nullptr)
                  return head;

            unordered_set<int> table;
            Node *first = head;
            Node *last = head->next;
            table.insert(first->data);

            while (last)
            {
                  if (table.insert(last->data).second)
                  {
                        first = first->next;
                        last = last->next;
                  }
                  else
                  {
                        while (last && !table.insert(last->data).second)
                              last = last->next;

                        first->next = last;
                        first = last;
                        last = (last) ? last->next : last;
                  }
                  /* code */
            }

            return head;
            // your code goes here
      }
};

//{ Driver Code Starts.

int main()
{
      // your code goes here
      int T;
      cin >> T;

      while (T--)
      {
            int K;
            cin >> K;
            struct Node *head = NULL;
            struct Node *temp = head;

            for (int i = 0; i < K; i++)
            {
                  int data;
                  cin >> data;
                  if (head == NULL)
                        head = temp = new Node(data);
                  else
                  {
                        temp->next = new Node(data);
                        temp = temp->next;
                  }
            }

            Solution ob;
            Node *result = ob.removeDuplicates(head);
            print(result);
            cout << endl;
      }
      return 0;
}
// } Driver Code Ends