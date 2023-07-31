#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int bellNumber(int n)
    {
        int bell[n+1][n+1];

        for(int i = 0; i <= n; i++)
        {
             
            bell[0][0] = 1;
            for (int i=1; i<=n; i++)
            {
                // Explicitly fill for j = 0
                bell[i][0] = bell[i-1][i-1];
 
                // Fill for remaining values of j
                for (int j=1; j<=i; j++)
                    bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
            }
        }
        return bell[n][0];
       // Code Here
    }        
        
       // Code Here

private:
    void calculate(int &top, int &bottom, int n)
    {
        
        
    }
};


//{ Driver Code Starts.



int main()
{
    Solution obj;
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<obj.bellNumber(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends