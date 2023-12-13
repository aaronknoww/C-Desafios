//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

// TERMINADO Y PASO LOS 1115 CASOS DE GFG

class Solution{
public:
	// #define ll long long
	ll countStrings(int n)
	{
	    if(n == 1)
	        return 2;
	    if(n == 2)
	        return 3;
	    long long dp[3];
	    dp[0] = 2;
	    dp[1] = 3;
	    
	    long long curr = 0;
	    long long first = 2;
	    long long second = 3;
	    const long long mod = 1e9 + 7;
	    
	    for(int i = 3; i<=n; i++)
	    {
	        dp[2] = (dp[1] + dp[0])%mod;
	        dp[0] = dp[1];
	        dp[1] = dp[2];
	    }
	    
	    return dp[2];
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends