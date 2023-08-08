//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// DUNCIONA BIEN PERO PARECE QUE EN LA PAGINA DE GFG, HAY UN ERROR.
class Array {
public:
  template <class T> static void input(vector<T> &A, int n) {
    for (int i = 0; i < n; i++) {
      scanf("%d ", &A[i]);
    }
  }

  template <class T> static void print(vector<T> &A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends

class Solution {
public:
  int stockBuyAndSell(int n, vector<int> &prices) {
    int max = 0, min = 0, profit = 0, aux = 0;

    for (int i = 0; i < n; i++) {

      while (i < n && prices[max] <= prices[i + 1])
      {
        max = ++i;
      }
      aux = prices[max] - prices[min];
      profit += (aux > 0) ? aux : 0;
      min = max + 1;
      max = min; 
      aux = 0;  
    }
    return profit;
    // code here
  }
};
//int myints[] = {8, 6, 7, 6, 5, 8, 9, 5, 5};
/*
1
7
100 180 260 310 40 535 695
*/
//{ Driver Code Starts.

int main() 
{

    //int myints[] = {100,180,260,310,40,535,695};
    //int myints[] = {8, 6, 7, 6, 5, 8, 9, 5, 5};
    int myints[] = {2, 2};
    //std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
   
    vector<int> prices(myints, myints + sizeof(myints) / sizeof(int));
    
    Solution obj;
    int res = obj.stockBuyAndSell(prices.size(), prices);

    cout << res << endl;
  
}

// } Driver Code Ends