//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;

// TERMINADO Y PASÓ LA PRUEBA GFG 410/310. 

class Solution
{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n)
    {
        vector<int> lead;
        
        int champ = a[n-1];
        lead.push_back(champ);
        
        for(int i = n-1; i > 0; i--)
        {            
          if( a[i-1] >= champ )
          {
            champ = a[i-1];
            lead.push_back(champ);
            
          }
          
        }
          reverse(lead.begin(), lead.end());
           
          return lead;
          
    }
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

/*
1
6
16 17 4 3 5 2
*/
// } Driver Code Ends