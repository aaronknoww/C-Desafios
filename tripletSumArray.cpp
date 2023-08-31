//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        unordered_map<int,int> table;
      int t = 0;

      for (int i = 0; i < n; i++)
      {
            if (A[i]< X)
                  table[A[i]]+=1;
                             
      }
      
      for (int i = 0; i < n; i++)
      {
            if (A[i]> X)
                  continue;
            for (int j = i+1; j < n; j++)
            {
                  //t = abs(X - A[i] - A[j]);
                  t = X - A[i] - A[j];
                  if(table.find(t)!=table.end())
                  {
                        if(t != A[i] && t != A[j])
                              return true;
                        if(t == A[i] && t == A[j] )
                        {
                            if(table[t] > 2)
                              return true;
                        }
                        else
                        {
                            if(t == A[i] && table[t] > 1)
                                  return true;
                            if(t == A[j] && table[t] > 1)
                                  return true;
                        }
                    
                  }

            }
      }

      return false;

        //Your Code Here
    }

};
/*
1
4 3
1 2 2 1
*/
//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends