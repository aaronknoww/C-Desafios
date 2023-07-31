//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Terminado y paso 1620 casos GFG
// } Driver Code Ends
class Solution
{

    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
       struct ord
       {
            bool operator() (pair<int, int> a,pair<int, int> b)
            {
                return a.first < b.first;
            }
        
       }objOrd; 
        //X= A + B; A = X - B
        multiset<int> aHash(A+0,A+N);
        multiset<int>:: iterator it;
        vector<pair<int,int>> res;
        

        for(int i = 0; i < M; i++)
        {
            it = aHash.find(X-B[i]);
            if(it != aHash.end())
            {
                res.push_back(pair<int,int>(*it , B[i]));
            }
        }
        sort(res.begin(), res.end(), objOrd);

        return res;
        // Your code goes here   
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends

/*
1
5 5 9
1 2 4 5 7
5 6 3 4 8
*/