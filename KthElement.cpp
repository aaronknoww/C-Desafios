//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//TERMINADO Y PASÓ LOS TEST EN GFG

// } Driver Code Ends
class Solution
{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int a1 = 0;
        int a2 = 0;
        int kthE = 0;
        int iter = 0;

        while(iter < k && a1 < n && a2 < m)
        {
            if(arr1[a1]<= arr2[a2])
            {
                kthE = arr1[a1];
                a1++;
            }
            else
            {
                kthE = arr2[a2];
                a2++;
            }
            iter++;
        }

        while(iter < k && a1 < n)
        {            
            kthE = arr1[a1];
            a1++;            
            iter++;
        }
        while(iter < k && a2 < m)
        {            
            kthE = arr2[a2];
            a2++;            
            iter++;
        }        
        return kthE;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}

/*
1
5 4 5
2 3 6 7 9
1 4 8 10
*/
// } Driver Code Ends