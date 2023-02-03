//{ Driver Code Starts
#include <bits/stdc++.h>

// TODO: DEPURARLO EN LA COMPUTADORA.
using namespace std;


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
        int nx = 0;
        long long total = 0;


        while (next < arr.end() && total < s || ini < arr.end())
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
                total +=  *next;
                next++;
                nx++;
            }
        }

        res[0] = -1;
        res.pop_back();
        return res;
        
        // Your code here
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

/*
1
5 12
1 2 3 7 5
*/

/*
1
5 12
1 20 3 7 500
*/