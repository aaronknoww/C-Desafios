//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
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

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
      private:
	Node* head;
      void insertBetween(Node* first, Node* second, Node* node)
	{
		first->next = node;
		node->next = second;
		return;

	}
	void insertBegin(Node * node)
	{		
		node->next = head;
		head = node;		
	}
    public:
    Node* insertionSort(struct Node* head_ref)
    {
	head = head_ref;
	Node* first = head;
	Node* node = head->next;
	Node * nx = head;

	while (node)
	{
		first->next = node->next; // to disconect a target node; 
		
		if(node->data <= head->data)
		{
			insertBegin(node);
			node = first->next;			
			continue;			
		}
		

		nx = head;
		while (nx && nx->next->data < node->data)
			nx = nx->next;
		insertBetween(nx, nx->next, node);
		node = first->next;
	}
	
        node = head;
	  return node;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
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

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
/*
1
10
30 23 28 30 11 14 19 16 21 25
*/