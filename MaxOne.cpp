//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LAS 20 PRUEBAS GFG
// } Driver Code Ends
class Solution
{
    public:
        int maxOnes (vector <vector <int>> &Mat, int N, int M)
        {
            int champ = 0;
            int rowChamp = 0;
            int res = 0;

            for(int i = 0; i < N; i++)
            {
                res = count(Mat[i].begin(), Mat[i].end(), 1);
                if(res>champ)
                {
                    champ = res;
                    rowChamp = i;
                }
            }

            return rowChamp;
            // your code here
        }
};

//{ Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}
// } Driver Code Ends