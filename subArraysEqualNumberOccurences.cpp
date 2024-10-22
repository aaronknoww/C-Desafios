//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// TERMINADO Y PASO EN GFG

class Solution
{
  public:
    int sameOccurrence(vector<int>& arr, int x, int y)
    {
        int n=arr.size();
        for(int i =0;i< n;i++)
        {
            if(arr[i] == x)
                arr[i]=1;
            else if(arr[i] == y)
                arr[i]=-1;
            else
                arr[i] =0;
        }
        int sum =0;
        int cnt =0;
        unordered_map<int,int> mp;
        mp[0]++;
        for(int i =0;i< n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum) != mp.end())
                cnt+=mp[sum];
            mp[sum]++;
        }
        return cnt;
        // code here
    }
};

//{ Driver Code Starts.
int main() 
{

        vector<int> arr {1,2,1};
        int x = 4;
        int y = 5;
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    return 0;
}
// } Driver Code Ends