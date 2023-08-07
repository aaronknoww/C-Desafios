#include<bits/stdc++.h>
using namespace std;

// TERMINADO Y PASO LOS 10134 CASOS DE GFG
// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long res = -99999999; // because it gonna use negative numbers.
        long long sum = 0;

        for(int i=0; i < n; i++)
        {
            sum += arr[i];
            res = (sum > res) ? sum : res;
            sum = (sum > 0) ? sum : 0;
        }

        return res;
        // Your code here
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends