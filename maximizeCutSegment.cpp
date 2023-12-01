//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
      int dp[n+1] = {0};
      int maxi = 0;
      int aux = 0;

      if(x==1 || y==1 || z==1)
      {
            return n;
      }
      
      for (int i = 2; i < n+1; i++)
      {
            maxi = 0;
            if(i - x >= 0)
            {
                 aux = dp[i-x] + 1;
                 maxi = (maxi > aux) ? maxi : aux;
            }
            if(i - y >= 0)
            {
                  aux = dp[i-y] + 1;
                  maxi = (maxi > aux) ? maxi : aux;
            }
            if(i - z >= 0)
            {
                  aux = dp[i-z] + 1;
                  maxi = (maxi > aux) ? maxi : aux;
            }
            aux = 0;
            dp[i] = maxi;

            /* code */
      }
      return dp[n];
      
        //Your code here
    }
};
/*
1
4
2 3 4

1
5
5 3 2

1
7
5 5 2
*/
//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends