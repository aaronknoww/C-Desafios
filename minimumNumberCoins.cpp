//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

//TERMINADO Y PASO LOS 144 DE GFG

class Solution{
public:
    vector<int> minPartition(int N)
    {
        //int conins[] =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> coins =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> res;
        int n = N;
        
        if(n == 0)
            return res;
        if(binary_search(coins.begin(), coins.end(), n))
        {
            res.push_back(n);
            return res;
        }
        int aux = 0;
        int it = 9;
        int cont = 0;   
        
        while (it >= 0 && n > 0)
        {
            aux = n % coins[it];
            if(aux != n)
            {
                cont = n/coins[it];
                for (int i = 0; i <cont; i++)
                    res.push_back(coins[it]);                
                    
                n %= coins[it];          

            }
            it--;
            
        }
        return res;
        

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends