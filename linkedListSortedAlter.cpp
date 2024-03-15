//{ Driver Code Starts
//TERMINADO Y PASO LOS 1115 CASOS DE GFG
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
	private:
	struct Node* reverseList(struct Node *head)
    {
        if(head->next == nullptr)
            return head;
        
        
        Node* sig = head->next;
        Node* ant = nullptr;
        Node * cur = head;
        
        while(sig != nullptr)
        {
            cur->next = ant;
            ant = cur;
            cur = sig;
            sig = sig->next;
            
        }
        cur->next = ant;
        return cur;
    }
    public:
    // your task is to complete this function
    // 1->9->2->8->3->7
    void sort(Node **head)
    {
      if(*(head)==nullptr)
            return;
      if((*head)->next == nullptr)
            return;

      Node* first = (*head);
	Node* ant = nullptr;
      Node* last = (*head)->next;
      Node* toAdd = last;
      while (last || first)
      {
		if(first)
		{
			ant = first;
			first->next =(first->next && first->next->next)? first->next->next : nullptr;
			first = first->next;

		}
		if(last)
		{
			last->next= (last->next && last->next->next)? last->next->next : nullptr;
			last = last->next;		            

		}
      }

	toAdd = reverseList(toAdd);

	while(toAdd)
	{
		ant->next = toAdd;
		ant = ant->next;
		toAdd = toAdd->next;
		/* code */
	}
	
	return;    

    }
};

/*
1
6
1 9 2 8 3 7

1
5
13 99 21 80 50
*/
//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends