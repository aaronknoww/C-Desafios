//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

// priority queue was use here.


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr)
    {
        //              dataType, Container,         function or object to make a comparation.
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        for(auto num : arr)
        {
            pq.push(num);
        }
        long long cost = 0;
        long long first = 0;
        long long second = 0;
        while(pq.size()>1)
        {
            first = pq.top();
            pq.pop();
            second = pq.top();
            pq.pop();
            cost += first + second;
            pq.push(first + second);
        }
        return cost;
        // Your code here
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends