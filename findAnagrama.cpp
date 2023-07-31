//{ Driver Code Starts

//FIND ANAGRAMA
// TERMINADO Y PASO 1100 CASOS DE GFG
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};
1
8
a a c c a a b a
aac

1
12
w o r v f o g v r o v w
vwor

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s)
    {
        vector<Node*> anag;
        Node* ini = head;
        Node* sig = head;
        Node* ant = nullptr;
        unordered_multiset<char> order(s.begin(), s.end());
        unordered_multiset<char>::iterator aux;
        
        int it = 0;

        while(sig != nullptr)
        {
            //myums.erase ( myums.find("cow"));  // erasing by range
            while( it < s.size() && sig)
            {
                ant = sig;
                aux = order.find(sig->data);
                if(aux == order.end())
                {
                    ini = ini->next;
                    sig = ini;
                    order.clear();
                    order.insert(s.begin(), s.end());
                    it = -1;
                    break;
                }
                order.erase(aux);
                sig = sig->next;
                it++;
            }
            if(it == s.size())
            {
                anag.push_back(ini);
                ini = sig;
                ant->next = nullptr;
            }
            it=0;
            order.clear();
            order.insert(s.begin(), s.end());                    
        }
        return anag;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends