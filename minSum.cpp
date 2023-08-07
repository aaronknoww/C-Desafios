#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    long long int minValue(int a[], int b[], int n)
    {
        multiset<int> a1(a+0,a+n);
        multiset<int,greater<int>> b1(b+0,b+n);
        long long int res = 0;

        auto itb = b1.begin();

        for(auto ita = a1.begin(); ita!= a1.end(); ita++)
        {
           res += *ita * *itb; 
            itb++;
        }    
       
        return res;
        // Your code goes here
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, i;
         cin>>n;
         int a[n], b[n];
         for(i=0;i<n;i++)
         cin>>a[i];
         for(i=0;i<n;i++)
         cin>>b[i];
         Solution ob;
         cout<< ob.minValue(a, b, n) <<endl;
     }
	
	return 0;
}
// } Driver Code Ends
/*
1
3
3 1 1
4 6 5
*/