//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//findSumLastNnodesLinkedList

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

//TERMINADO Y PASO EN GFG

// } Driver Code Ends
class Solution {
  public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node* head, int n)
    {
        Node * first = head;
        Node * last = head;
        int res = 0;
        if(n == 1)
        {
            while(first->next != nullptr)
                first = first->next;
            return first->data;            
        }

        for(int i = 0; i < n-1; i++)
        {
            last = last->next;
        }

        while(last->next != nullptr)
        {
            last = last->next;
            first = first->next;
        }
        while(first != last)
        {
            res += first->data;
            first = first->next;
        }
        res += first->data;
        return res;
        // Code here
    }
};

//{ Driver Code Starts.

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
        int n;
        cin >> n;
        cin.ignore();
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        cout << ob.sumOfLastN_Nodes(head, n) << endl;
    }
    return 0;
}
// } Driver Code Ends