//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
     
        qsort(a, n, sizeof(int), [](const void* a, const void* b)
        {
            if ( *(int*)a <  *(int*)b ) return -1;
            if ( *(int*)a == *(int*)b ) return 0;
            if ( *(int*)a >  *(int*)b ) return 1;
            return 0;
        });

        
        // code here 
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends