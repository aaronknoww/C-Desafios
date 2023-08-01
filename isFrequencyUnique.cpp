//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 1120 CASOS DE GFG.
// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int, int> hmap;
        unordered_map<int, int>::iterator itM;
        unordered_set<int> res;
        //pair<unordered_map<int, int>::iterator, bool> res;
        for(int i=0; i < n; i++)
        {
            itM = hmap.find(arr[i]);
            if(itM != hmap.end())
                itM->second = 1 + itM->second;
            else
                hmap.insert({arr[i],1});          
        }

        itM = hmap.begin();

        while(itM != hmap.end())
        {
            if(!res.insert(itM->second).second)
                return false;
            itM++;
        }
        return true;
    }
};
/*
1
5
1 1 5 5 5
*/
//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends
