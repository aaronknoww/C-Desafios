//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 1115 DE GFG

// } Driver Code Ends
// User function template for C++
// [0, 0, 1, 1, 0]
class Solution {
  public:
    void segregate0and1(vector<int> &arr)
    {
      int i = 0;
      int j = arr.size()-1;
      while( i < j )
      {

            if (arr[i] == 0 && arr[j] == 1)
            {
                  i++;
                  j--;
            }
            else if(arr[i] == 1 && arr[j]==0)
            {
                  arr[i]=0;
                  arr[j]=1;
                  i++;
                  j--;
            }
            i = (arr[i] == 0)? i+1 : i;
            j = (arr[j] == 1)? j-1 : j;
            
            
      }
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends