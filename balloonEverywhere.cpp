//{ Driver Code Starts
//Initial Template for C++

// TERMINADO Y PASO LOS 1021 CASOS DE GFG

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s)
    {
        if(s.size()<6)
            return 0;
            
        unordered_map<char, int> ballon{{'b',0 },{'a',0 },{'l',0},{'o',0 },{'n',0 }}; //balloon
        int min = 999999999;;

        for(char c : s )
        {
            if(ballon.find(c)!=ballon.end())
                  ballon[c]++;            

        }        
        ballon['o']/=2;
        ballon['l']/=2;
        
        for(unordered_map<char,int>::iterator it = ballon.begin(); it != ballon.end(); it++ )
        {
            if(it->second == 0)
                return 0;
            min = (it->second < min)? it->second : min;
        }
        
        return min;

        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends