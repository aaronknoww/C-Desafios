//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// TERMINADO Y PASO LOS 1120 CASOS DE GFG.

class Solution{
  public:
    int longestKSubstr(string s, int k)
    {
        int ptrFir = 0;
        int ptrSec = 0;
        unordered_map<char,int> table;
        int champ = 0;
        int cont = 0;
        bool check = false;

        while (ptrSec < s.size())
        {
            table[s[ptrSec]] += 1;
            cont = ptrSec - ptrFir + 1; 
            ptrSec++;
            if(table.size() >= k)
                check = true;

            while ( table.size() > k)
            {
                table[s[ptrFir]] -= 1;
                if(table[s[ptrFir]] < 1)
                    table.erase(s[ptrFir]);                
                ptrFir++;
                cont=0;                
            }
            champ = (cont > champ) ? cont : champ;
                
        }        
        
        return (check) ? champ : -1;
               
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

/*
1
aabacb
3

1
untxym
4

1
iyaegalunnzv
3
*/
// } Driver Code Ends