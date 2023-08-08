
// WHITOUT RECURSION

//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

// TERMINADO Y PASO LOS 1120 CASOS DE GFG

/* Function to print an array */
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// } Driver Code Ends
class Solution {
private:
  // stack<pair<int,int>> rest;
  vector<pair<int, int>> rest;

public:
  // Function to sort an array using quick sort algorithm.
  void quickSort(int arr[], int low, int high) {

    rest.push_back({low, high});
    pair<int, int> next;
    do {
      partition(arr, low, high);
      next = rest.back();
      low = next.first;
      high = next.second;
    } while (!rest.empty());
    // code here
  }

public:
  int partition(int arr[], int low, int high) {
    srand(time(NULL));
    if (low == high) {
      rest.pop_back();
      return low;
    }

    int p = -10;
    int aux = 0;
    int l = low;
    int r = high;

    p = l + rand() % (r - l);
    aux = arr[l];
    arr[l] = arr[p];
    arr[p] = aux;
    p = l;
    do {
      while (arr[p] > arr[l + 1] && l != r) {
        aux = arr[l + 1];
        arr[l + 1] = arr[p];
        arr[p] = aux;
        l++;
        p = l;
      }
      while (arr[p] <= arr[r] && l != r)
        r--;

      if (arr[l + 1] > arr[r] && l + 1 < r) {
        aux = arr[l + 1];
        arr[l + 1] = arr[r];
        arr[r] = aux;
      }

    } while (l < r);

    rest.pop_back();

    if (l - 1 >= low) // l = pivote;
      rest.push_back({low, l - 1});
    if (r + 1 <= high) // r = pivote;
      rest.push_back({r + 1, high});

    return arr[r];
  }

  // Your code here
};

/*

1
8
24 18 38 43 14 40 1 54

*/
//{ Driver Code Starts.
int main() {
  int arr[1000], n, T, i;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);
    Solution ob;
    ob.quickSort(arr, 0, n - 1);
    printArray(arr, n);
  }
  return 0;
}
// } Driver Code Ends