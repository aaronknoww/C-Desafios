//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum)
    {
        int remain = 0;
        long long resK = 0; // to sum 0 to K elements.
        vector<long long >::iterator next = GeekNum.begin();
        if(K == 1)
            return GeekNum[0];
        if(N == K)
            return GeekNum.back();

        
        remain = N - K;
        int debuGeek;
        long long sum = 0;

        for(int i=0; i <  remain; i++)
        {
            sum = 0;
            for(int j = i; j < GeekNum.size(); j++)
            {
                sum +=  GeekNum[j];
            }
            GeekNum.push_back(sum);
            //debuGeek = accumulate(next, GeekNum.end(),0);
            //GeekNum.push_back(debuGeek);
            //GeekNum.push_back(accumulate(next, GeekNum.end(),0));
            debuGeek = GeekNum.size();
            debuGeek = GeekNum[GeekNum.size()-1];
            next++;    
        }       
        
        return GeekNum.back();
        //return GeekNum[GeekNum.size()-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}
/*
1
5 3
0 1 2

1
10 3
3 2 1

*/
// } Driver Code Ends
