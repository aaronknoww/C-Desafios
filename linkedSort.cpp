//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
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
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head)
    {
        Node *sig =  nullptr;
        Node *aux =  nullptr;
        Node *ptr0 = nullptr;
        Node *ptr1 = nullptr;
        Node *ptr2 = nullptr;
        Node *ptr0Front = nullptr;
        Node *ptr1Front = nullptr;
        Node *ptr2Front = nullptr;
        
        while(sig)
        {
            if(sig->data == 0)
            {
                if(ptr0 == nullptr)
                {
                    ptr0Front = sig; // this pointer never move again.
                    ptr0 = sig;
                    aux = sig;
                    sig = sig->next;
                    aux->next = nullptr;
                }
                else
                {
                    
                    aux = sig; //take object adress 
                    sig = sig->next; // move to next object            
                    aux->next = ptr0; //conect current object with head.
                    //aux->next = ptr0->next; //conect current object with head.
                    ptr0 = aux; // point to aux object
                }
            }
            else if(sig->data == 1)
            {
                if(ptr1 == nullptr)
                {
                    ptr1Front = sig; // this pointer never move again.
                    ptr1 = sig;
                    aux = sig;
                    sig = sig->next;
                    aux->next = nullptr;
                }
                else
                {
                    
                    aux = sig; //take object adress 
                    sig = sig->next; // move to next object            
                    aux->next = ptr1; //conect current object with head.
                    //aux->next = ptr0->next; //conect current object with head.
                    ptr1 = aux; // point to aux object
                }
            }
            else if(sig->data == 2)
            {
                if(ptr2 == nullptr)
                {
                    ptr2Front = sig; // this pointer never move again.
                    ptr2 = sig;
                    aux = sig;
                    sig = sig->next;
                    aux->next = nullptr;
                }
                else
                {
                    
                    aux = sig; //take object adress 
                    sig = sig->next; // move to next object            
                    aux->next = ptr2; //conect current object with head.
                    //aux->next = ptr0->next; //conect current object with head.
                    ptr2 = aux; // point to aux object
                }
            }
            else
                return nullptr;
        
        }
        
        ptr1Front = ptr2;
        ptr0Front = ptr1;
        return ptr0;
        // Add code here
        
    }
};

/*
1
8
1 2 2 1 2 0 2 2
*/
//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}