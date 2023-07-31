//{ Driver Code Starts
#include <iostream>
using namespace std;

// TERMINADO Y PASO LOS 210 CASOS GFG

// } Driver Code Ends
class Solution {
public:
  // Function to find equilibrium point in the array.
  // a: input array
  // n: size of array
  int equilibriumPoint(long long a[], int n) {
    if (n == 1)
      return a[0];
    if (n == 2)
      return -1;

    long long total = 0;
    long long left, right, current;
    int it = 1;
    left = 0;
    right = 0;
    current = a[0];

    // int total = accumulate(a,a+n,0);
    for (int i = 0; i < n; i++)
      total += a[i];

    do {
      left = current;
      current += a[it];
      right = total - current;
      it++;
    } while (left != right && it < n);

    return (left == right) ? it : -1;
  }
};
/*
1
5
1 3 5 2 2
*/
//{ Driver Code Starts.

int main() {

  long long t;

  // taking testcases
  cin >> t;

  while (t--) {
    long long n;

    // taking input n
    cin >> n;
    long long a[n];

    // adding elements to the array
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }

    Solution ob;

    // calling equilibriumPoint() function
    cout << ob.equilibriumPoint(a, n) << endl;
  }
  return 0;
}

// } Driver Code Ends