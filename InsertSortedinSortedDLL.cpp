//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*structure of the node of the DLL is as
struct Node {
    int data;
    struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        if(head->data >= x)
        {
            Node *aux = new Node();
            aux->data = x;
            aux->next = head;
            aux->prev = nullptr;
            head->prev = aux;
            head = aux;
            return head;                
        }
        if(head->next == nullptr)
        {
            if(head->data >= x)
            {
                Node *aux = new Node();
                aux->data = x;
                aux->next = head;
                aux->prev = nullptr;
                head->prev = aux;
                head = aux;
                return head;                
            }
            head->next = new Node();
            head->next->data = x;
            head->next->prev = head;
            return head;            
        }
        // search for the position to insert
        Node* curr = head;
        Node* ant = NULL;
        while (curr != NULL && curr->data < x)
        {
            ant = curr;
            curr = curr->next;                
        } 

        // to insert at the last position.
        if(curr == nullptr)
        {
            ant->next = new Node();
            ant->next->data = x;
            ant->prev = ant;
            return head;
        }

        ant->next = new Node();
        ant->next->data = x;
        ant->next->next = curr;
        ant->next->prev = ant;
        curr->prev = ant->next;
        return head;
        // Code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends