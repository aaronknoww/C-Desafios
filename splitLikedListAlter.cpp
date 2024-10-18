//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head)
    {
         vector<Node*> res;
         Node * last = nullptr;
         Node * l1 = nullptr;
         Node * l2 = nullptr;

        if (head == nullptr) {
            return res; // Return empty vector if head is null
        }
    
        // If the list has only one node
        if (head->next == nullptr) {
            res.push_back(head);
            res.push_back(nullptr);
            return res; // Return the vector after adding the node
        }

        // Only two nodes in the list
        if(head->next->next == nullptr)
        {
            res.push_back(head);
            res.push_back(head->next);
            return res; // Return the vector after adding the nod
        }

        res.push_back(head);
        res.push_back(head->next);
        
        last = head->next->next;
        res[0]->next = last;
        res[1]->next = (last) ? last->next : nullptr;
        l1=last;
        last = last->next;
        l2 = last;
        last = (last) ? last->next : nullptr; 

        while(last)
        {
            l1->next = last;
            l1 = last;
            last = (last) ? last->next : nullptr;
            l2->next = last;
            l2 = last;
            last = (last) ? last->next : nullptr;
        }

        return res;
        // Your code here
    }
};

//54 68 68 70 12 64 37 91 63 30 25

//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends