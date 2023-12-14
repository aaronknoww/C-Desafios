//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

//TERMINADO Y PASO LOS 1115 CASOS DE GFG

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k)
    {
        long long mod = 1e9 + 7;
        if(n == 0)
            return 0;
        if(n==1)
            return k;
        if(n==2)
            return static_cast<long long>(k)*k;
            
        //long long diff = (k*(k-1))%mod;// for 2
        long long diff = static_cast<long long>(k)*(k-1);// for 2
        long long same = k;
        long long prev = 0;


      for (int i = 3; i <= n; i++)
      {
          prev = diff;//6
          diff = ((same + diff) * (k-1)) % mod;
          same = prev;
      }

      return (same + diff) % mod;

        // code here
    }
};


//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends