//{ Driver Code Starts
//Initial template for C++



#include <bits/stdc++.h> 
using namespace std;

//TERMINADO Y PASO LOS 22 CASOS GFG

// } Driver Code Ends
//User function template in C++


class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        multiset<int> sorA1(A1.begin(), A1.end());
        vector<int> res;
        int cant = 0;

        for(vector<int>::iterator i = A2.begin(); i != A2.end(); i++)
        {
            cant = sorA1.erase(*i); 
            if( cant > 0)
                res.insert(res.end(), cant, *i); // to insert the number, cant times.            
        }

        if(sorA1.size() > 0)
            res.insert(res.end(), sorA1.begin(), sorA1.end());

        return res;
    } 
};

/*
1
11 4
2 1 2 5 7 1 9 3 6 8 8
2 1 8 3
*/

//{ Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 

// } Driver Code Ends