//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

//TERMINADO Y PASO LOS 1120 CASOS DE GFG

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr+n);
        if(arr[0] > 0 || n < 3)
            return false;
        
        int *p = nullptr;
        
        int right = 0;
        int max = 0;
        int sum = 0;

        for(int left = 0; left < n-2; left++)
        {
            right = left +1;
            max = n-1;
            while(right != max)
            {
                if(arr[left]+arr[right]+arr[max] < 0)
                    right++;
                else if(arr[left]+arr[right]+arr[max] > 0)
                    max--;
                else
                    return true;
            }
        }
        return false;
        //Your code here
    }
};
/*
1
3
0 0 0

1
6
-65 -21 5 8 60 93
*/
//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends