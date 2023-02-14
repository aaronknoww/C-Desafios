//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// TERMINADO Y PASÓ LOS 307 CASOS DE GFG

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n)
    {
        sort(array.begin(), array.end());
        array.push_back(9999999);

        for (int i = 0; i < array.size(); i++)
        {
            if(array[i] != i+1)
            {
                return i+1;
            }
        }
        return 0;        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends
/*
1
10
6 1 2 8 3 4 7 10 5
*/