//{ Driver Code Starts

//TERMINADO Y PASO LOS 2113 CASOS DE GFG

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

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
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
      Node* first = head;
      Node* end = head;
      Node* aux = nullptr;

      for(int i = 1; i < k; i++)
            first = first->next;
      
      if(first->next == nullptr)
            return head;

      end = first;
      while(end->next)
            end = end->next;
      
      aux = first;
      first = first->next;
      aux->next = nullptr;
      end->next = head;

      return first;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends