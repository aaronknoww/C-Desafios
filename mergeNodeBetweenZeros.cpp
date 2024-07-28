//{ Driver Code Starts
// Initial Template for C++

//TERMINADO Y PASO LOS 155 GFG

#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
      
  
  public:
      ListNode *mergeNodes(ListNode *head)
      {
            ListNode * first = head;
            ListNode* second = head->next;
            int sum = 0;
            
            //[0,3,1,0,4,5,2,0]

            while (second)
            {
                  while(second && second->val !=0)
                  {
                        sum += second->val;
                        second = second->next;
                  }
                  first->val = sum;
                  first->next = (second->next == nullptr)?nullptr:second;
                  first = second;
                  second = second->next;
                  sum = 0;
                  /* code */
            }
            return head;

            
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

1
4
1 2 3 4

1
5
1 1 2 3 3

1
5
5 1 1 2 2
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
        //head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends