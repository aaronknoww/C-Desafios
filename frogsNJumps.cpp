//FROGS AND JUMP

//TERMINADO Y PASO 1065 CASOS EN GFG.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[])
    {
        set<int> fg(frogs, frogs + N); //To order and remove duplicates
        //set<int>::iterator itFg = fg.begin();
        unordered_set<int> leHash(leaves);
        int jump = 0;

        for(int i = 1; i <= leaves; i++)
            leHash.insert(i);

        if(fg.find(1) != fg.end())
            return 0;

       // itFg = fg.begin();
        for(set<int>::iterator itFg = fg.begin(); itFg != fg.end(); itFg++)
        {
            jump = *itFg;
            while(jump <= leaves)
            {
                leHash.erase(jump);
                jump += *itFg;
                
            }
            if(leHash.empty())
                return 0;
        }
        return leHash.size();
        // Code here
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends