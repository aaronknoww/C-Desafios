//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


/// TERMINADO Y PASO LOS 1121 CASOS DE GFG

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum)
    {
        vector<vector<long long>> dpWays(N + 1, vector<long long>(sum + 1, 0));
        int itCoin = 0; // iterate thru every coin

        dpWays[0][0] = 1;

        for (int row = 1; row <= N; row++)// from the dpWays matrix 
        {
            dpWays[row][0] = 1;
            for (int col = 1; col <= sum; col++)
            {
                dpWays[row][col] = (col - coins[itCoin] >= 0) ? dpWays[row][col - coins[itCoin]] + dpWays[row - 1][col] : dpWays[row - 1][col];
            }
            itCoin++;
        }

        return dpWays[N][sum];

        // code here.
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends