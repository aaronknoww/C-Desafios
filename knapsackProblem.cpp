//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
      class Item
      {
            public:
            int wt;
            int val;
            Item(int wt, int val)
            {
                  this->wt = wt;
                  this->val = val;
            }
            bool operator<(const Item &item) const
            {
                  if(this->wt == item.wt && this->val >= item.val)
                        return true;
                  if(this->wt < item.wt )
                        return true;
                  else
                        return false;
            }
            bool operator<=(const Item &item) const
            {
                  if(this->wt <= item.wt && this->val >= item.val)
                        return true;
                  else
                        return false;
            }
            bool operator==(const Item &item) const
            {
                  if(this->wt == item.wt)
                        return true;
                  else
                        return false;
            }

      };
    public:
    //Function to return max value that can be put in knapsack of capacity W.

    //TERMINADO Y PASO LOS 1210 CASOS DE GFG
    
    int knapSack(int W, int wt[], int val[], int n) 
    {
        
      multiset<Item> items;

      for (int i = 0; i < n; i++)
      {
            items.insert(Item(wt[i],val[i]));
            
      }      
      int dp[n+1][W+1] = {0};

      for (int i = 0; i < n+1; i++)
            for (int j = 0; j < W+1; j++)
                  dp[i][j] = 0;

      
     
      int r = 1;

      for(multiset<Item>::iterator it = items.begin(); it != items.end(); it++)
      {
            for (int c = 1; c <= W; c++)
            {
                   //int sumCol = (c- it->wt);
                  if(c- it->wt >= 0)
                        dp[r][c] = max( dp[r-1][c], dp[r-1][(c- it->wt)] + it->val);
                  else
                        dp[r][c] = dp[r-1][c];
            }
            r++;
      }

      return dp[n][W];

       // Your code here
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends