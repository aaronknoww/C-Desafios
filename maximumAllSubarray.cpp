
#include <bits/stdc++.h>
using namespace std;

//MAXIMUM OF ALL SUBARRAY
//TERMIADO Y PASO LOS 166 CASOS DE GFG 

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        int itIni = 0;
        int itFin = k-1;
        multiset<int> window;
        multiset<int>::iterator itW;

        window.insert(arr, arr + k);

        res.push_back(*window.rbegin());
        while(itFin < n)
        {
            itW = window.find(arr[itIni]);
            window.erase(itW);
            itIni++;
            itFin++;
            window.insert(arr[itFin]);
            res.push_back(*window.rbegin());
        }
        // your code here

        return res;
    
    }
};

/*
1
9 3
1 2 3 1 4 5 2 3 6
*/
//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends'/;
