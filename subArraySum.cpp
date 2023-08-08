//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
//Sub array with given sum
//TERMINADO Y PASO LOS 165 CASOS DE GFG

// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        vector<int>::iterator ini = arr.begin();
        vector<int>::iterator next = arr.begin();
        vector<int> res(2);
        int i = 1;
        int nx = 1;
        long long total = 0;

        if(s==0)
        {
            res[0] = -1;
            res.pop_back();
            return res;
        }


        while(total<s)
        {
            total += *ini;
            nx++;
        }


        while (next < arr.end() || ini < arr.end())
        {
            if(total == s)
            {
                res[0] = i;
                res[1] = nx;
                return res; // Regresa el resultado
            }
            if(total > s)
            {
                total -= *ini;
                ini++;
                i++;                
            }
            else
            {
                total += *next;
                next++;
                nx++;
            }
        }

        res[0] = -1;
        res.pop_back();
        return res;
        
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends