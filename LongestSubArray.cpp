//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:

    void backFoward(vector<int> &arr, int ini, int end, int &lenChamp)
    {
        bool res = true;
        int elem = end - ini;
        int lenTemp = 0;
        int iter = 0;
        while (arr[ini] != 0 && lenChamp + iter < elem )
        {
            for (int i = 0; arr[i+ini] !=0; i++)
            {
                res = (arr[i+ini] < 0) ? !res : res; 
                lenTemp++;
                if(res && lenChamp < lenTemp)
                    lenChamp = lenTemp; 
            }
            ini++;
            lenTemp = 0;
            res = true;
            iter++;                        
        }        
    }
    
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n)
        {
            bool res = true;
            int ini = 0;
            int lenChamp = 0;
            int lenTemp = 0;

            while ( ini < n && lenChamp + ini < n )
            {
                for (int i = ini; i < n; i++)
                {
                    if(arr[i]==0)
                    {
                        if(lenChamp >= i - ini)
                        {
                            lenTemp = 0;
                            res = true;
                            ini =  i + 1;
                            continue;
                        }
                        else
                        {
                            backFoward(arr, ini + 1, i, lenChamp);
                            res = true;
                            lenTemp = 0;
                            ini =  i + 1;
                            continue;                        

                        }
                        
                    }
                    res = (arr[i] < 0) ? !res : res; //TODO: REVISAR QUE SI NIEGUE EL VALOR.
                    lenTemp++;
                    if(res && lenChamp < lenTemp)
                        lenChamp = lenTemp; 

                }               

                ini++;
                lenTemp = 0;
                res = true;                
            }
            return lenChamp;           
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends



/*
1
5
0 -9 5 0 -6

r = 1;

1
8
9 -1 8 6 0 8 -2 3
r = 2;

1
6
0 -7 4 6 0 4
r=2;

1
5
-1 2 3 4 5
r=4;

1
5
-7 1 0 -7 0
r=1;

1
8
-8 9 5 -7 -5 3 0 4
r=5;

1
5
1 -2 3 -4 -1

1
7
10 1 -2 -3 -4 -5 -6

1
11
-5 10 1 -4 -5 -6 -4 3 2 5 8  

1
7
10 1 -2 0 -4 -5 6

   arr[] ={10, 1, -2, -3, -4, -5, -6}  = - +
   arr[] ={10, 1, 0, -3, -4, -5, -6} 
   6
*/

