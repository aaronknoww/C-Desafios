//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 1115 CASOS DE GFG.

// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks)
    {
        unordered_map<char,int> hmap;
        unordered_map<char,int>:: iterator itMap;
        int maxi = 0;
        int cant = 0;
        int res = 0;

        for(int i = 0; i < N; i++)
        {
            itMap = hmap.find(tasks[i]);
            if(itMap == hmap.end())
                hmap.insert({tasks[i], 1});
            else
               itMap->second += 1;             
        }
        for(unordered_map<char,int>:: iterator it = hmap.begin(); it!=hmap.end(); it++)
        {
           if(it->second > maxi)
           {
               maxi = it->second;
               cant = 1;
           }
           else if(it->second == maxi)
                cant++; 
        }
        res = (maxi-1) * (K+1) + cant;
        
        

        // res = (maxfreq-1)*(k+1) + (total elements with max freq)= (6-1)*(2+1) + 1 = 16
        return (res >= N) ? res : N;
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends