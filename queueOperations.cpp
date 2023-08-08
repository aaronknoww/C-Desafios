//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASO LOS 1120 CASOS DE GFG
//Queue Operations
// } Driver Code Ends
//User function Template for C++
// Helper class Solution to implement 
// insert() and findFrequency()
class Solution
{
    private:
    unordered_multimap<int,int> dic;
    unordered_multimap<int,int>::iterator itDic;
    public:
    // Function to insert element into the queue
    void insert(queue<int> &q, int k)
    {
        q.push(k);
        itDic = dic.find(k);
        if(itDic != dic.end())
            itDic->second = itDic->second + 1; 
        else
            dic.insert({k,1});
        // Your code here
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k)
    {
       itDic =  dic.find(k);
        if(itDic != dic.end())
            return itDic->second;
        else
            return -1;
        // Your code here
    }

    
};
/*
1
8
1 2 3 4 5 2 3 1
5
1 3 2 9 10
*/
//{ Driver Code Starts.
int main() {
    
		int testcase;
		cin>>testcase;
		
		while(testcase-- > 0){
		    // Declaring Queue
		    queue<int> q;
		    int n, k;
		    cin>>n;
		    
		    // Invoking object of Geeks class
		    Solution obj;
		    
		    for(int i = 0;i<n;i++){
		        cin >> k;
		        obj.insert(q, k);
		    }
		   
		    int m;
		    cin >> m;
		    for(int i = 0;i<m;i++){
		        cin >> k;
		        int f = obj.findFrequency(q, k);
		        if(f != 0){
		            cout<<f<<endl;
		        }
		        else{
		            cout<<"-1\n";
		        }
		    }
		}
	return 0;
}
// } Driver Code Ends