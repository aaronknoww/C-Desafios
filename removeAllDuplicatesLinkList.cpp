//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution
{
    private:
    void moveHead(Node *& head)
    {
        while ( head->next->data == head->data ) // to erase all duplica from the begining.
      {
            head =  head->next;
            if(head == nullptr)
                  return;

      }
      head =  head->next;

    }
  public:
    Node* removeAllDuplicates(struct Node* head)
    {
        if(head->next == nullptr)
            return head;

        
        while(head->next->data == head->data)
        {
            while (head->next->data == head->data) // to erase all duplica from the begining.
            {
                head = head->next;
                if (head == nullptr)
                    return head;
            }
            head = head->next;
        }

        Node* first = head;
        Node* second = head->next;
        bool enter = false;
      //List = 23->28->28->35->49->49->53->53

        
        while (second)
        {
            
            while(second->next->data && second->data == second->next->data)
            {
                enter = true;
                while (second->next->data && second->data == second->next->data)
                {
                    second = second->next;
                    if (second == nullptr)
                    {
                        first->next = nullptr;
                        return head;
                    }
                    
                }
                second = (second) ? second->next : second;
                
                if(second == nullptr)
                {
                    first->next = nullptr;
                    return head;
                }         

            }
            if(enter)
            {
                first->next = second;
                first = second;
            }
            else
            {
                first = second;
                second = second->next;
            }
            enter = false;
        }
        
        
        
        return head;     

        // code here
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/*
1
8
23 28 28 35 49 49 53 53
*/
// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends