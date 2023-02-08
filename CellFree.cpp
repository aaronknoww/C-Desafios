//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

//FUNCIONA PERO ES LENTO POR ESO NO PASA EL CASO 100 DE GFG
// se tiene que resolver con calculos sin recorrer la matriz

// } Driver Code Ends
//User function Template for C++


class Solution
{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr)
  {
    int total = n * n;
    int remCol[n]; //remaining columns
    int remRow[n]; //remaining rows
    vector<vector<int>>matrix(n,vector<int>(n));
    vector<long long int> res;  
    

    memset(remCol, 0, n*sizeof(remCol[0]));
    memset(remRow, 0, n*sizeof(remRow[0]));

    for (auto &&cor : arr)
    {
        //row = cor[0]
        //col = cor[1]

        if(remRow[cor[0]-1] != 1) // check if not visited yet.
        {
            remRow[cor[0]-1] = 1;
            // It is neccesari check the row.
            for (int i = 0; i < n; i++)
            {
                if(matrix[cor[0]-1][i] == 0)
                {
                    matrix[cor[0]-1][i] = 1;
                    total--;
                }
            }
        }
        if(remCol[cor[1]-1] != 1) // check if not visited yet.
        {
            remCol[cor[1]-1] = 1;
            // It is neccesari check the row.
            for (int i = 0; i < n; i++)
            {
                if(matrix[i][cor[1]-1] == 0)
                {
                    matrix[i][cor[1]-1] = 1;
                    total--;
                }
            }
        }

        res.push_back(total);
    }
    return res;   

  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


/*
1
3 3
2 2
2 3
3 2

int arrayValues[number];
    
    memset(arrayValues, 0, number*sizeof(arrayValues[0]));
*/
// } Driver Code Ends