
#include <bits/stdc++.h>
using namespace std;

// TERMINADO Y PASÓ TODOS LOS CASOS GFG

class Solution
{
    public:
    int maxLen(vector<int>&A, int n)
    {
        int sum = 0;
        int largest = 0;
        unordered_map<int, int> saveSum;
        unordered_map<int, int>::iterator res;
        int backInd = 0; // to store the index of the first occurrence of sum 

        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if(sum == 0)
            {
                largest = ( largest < i+1 ) ? i+1  : largest;
            }
            else if(!saveSum.insert({sum, i}).second)
            {
                res = saveSum.find(sum);                
                backInd = res -> second;
                largest = ( largest < i - backInd) ? i - backInd : largest;
                            }          
                        
        }
        return largest;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}

/*
1
8
15 -2 2 -8 1 7 10 23

1
4
10 -2 2 -10

*/

// } Driver Code Ends