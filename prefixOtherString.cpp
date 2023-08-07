

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

//TERMINADO Y PASO LOS 1115 CASOS DE GFG

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str)
    {    
        if(k > str.length())
            return 0;
        bool flag = true;
        int cont = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i].length() < k)
                continue;
          
            for(int j = 0; j<k; j++)
            {
                if(arr[i][j] != str[j])
                {
                    flag = false;
                    break;
                }
            }
            cont += (flag) ? 1 : 0;
            flag = true;
        }
        return cont;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 
