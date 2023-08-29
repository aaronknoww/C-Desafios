//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

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

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *compute(Node *head)
    {
        if (head->next == nullptr)
            return head;

        Node *first = head;
        Node *middle = head->next;
        Node *last = (middle) ? middle->next : nullptr;

        if (last == nullptr)
        {
            // if enter here is because there are only two nodes

            if (first->data >= middle->data)
                return first;

            first = middle;
            return first;
            /* code */
        }

        first->next = nullptr;

        //*****reverse link list
        //   0   1  2
        // <-F <-M L->
        do
        {
            middle->next = first;
            first = middle;
            middle = last;
            last = last->next;
            /* code */
        } while (last != nullptr);

        middle->next = first;
        last = middle;
        head = last;

        // *************************

        while (first)
        {
            if (first->data < last->data)
            {
                while (first && first->data < last->data)
                    first = (first) ? first->next : nullptr;

                // first= first->next;
                last->next = first;
                last = first;
            }
            else
            {
                last = first;
                first = (first) ? first->next : nullptr;
            }
            /* code */
        }

        // reverse list
        first = head;
        middle = first->next;
        last = (middle) ? middle->next : nullptr;

        if (first->next == nullptr)
            return first;

        if (last == nullptr)
        {
            middle->next = first;
            first->next = nullptr;
            return middle;
        }

        first->next = nullptr;
        do
        {
            middle->next = first;
            first = middle;
            middle = last;
            last = last->next;
            /* code */
        } while (last != nullptr);

        middle->next = first;
        last = middle;
        head = last;
        return head;

        // your code goes here
    }
};

//{ Driver Code Starts.

int main()
{
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
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}

// } Driver Code Ends