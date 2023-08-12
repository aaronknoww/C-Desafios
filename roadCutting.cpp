//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// FUNCIONA PERO FALLA LA PAGINA DE GFG, AUNQUE EN EL CASO QUE FALLA SI PASA SI SE COMPILA EN LA PAGINA. 

// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n)
    {
        vector<int> dpMax(n);
        dpMax[0] = 0;
        dpMax[1] = price[0];
        int number = 0;
        int rest = 0;
        int max = 0;
        int current = 0;

        for (int i = 2; i <= n; i++)
        {
            max = price[i-1];
            do
            {
                number++;
                rest = i - number;
                current += dpMax[number];
                current += dpMax[rest];
                max = (current > max)? current : max;

            }
            while(rest >= number);
            dpMax[i] = max;
            current = 0;
            number = 0;
            /* code */
        }
        return dpMax[n];
           

        //f(n) = f(n) + f(n-1) + f(n-2)... // until r = n-2; r >= number

/*
1
8
1 5 8 9 10 17 17 20
*/

        //code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends