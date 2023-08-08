//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
         set<int> setA;
        set<int> setB;
        set<int>::iterator itA = setA.begin();
        set<int>::iterator itB = setB.begin();
        int rep = 0;
        int rest = abs(n - m);
        int totA = 0;
        int totB = 0;
        int dif = 0;

        if (n > m)
        {
            for (int i = 0; i < m; i++)
            {
                setA.insert(A[i]);
                setB.insert(B[i]);
                totA += A[i];
                totB += B[i];

            }
            for (int i = 0; i < rest; i++)
            {
                setA.insert(A[i + m]);
                totA += A[i + m];
            }
        }
        else if (m > n)
        {
            for (int i = 0; i < n; i++)
            {
                setA.insert(A[i]);
                setB.insert(B[i]);
                totA += A[i];
                totB += B[i];
            }
            for (int i = 0; i < rest; i++)
            {
                setB.insert(B[i + n]);
                totB += B[i + n];
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                setA.insert(A[i]);
                setB.insert(B[i]);
                totA += A[i];
                totB += B[i];
            }
        }

        itA = setA.begin();
        itB = setB.begin();

        if ((totA - totB) % 2 != 0)
            return -1;

        dif = (totA - totB) / 2; // is the diference necessary between the 2 arrays in order to acomplish the goal.

        if (dif > 0) // move in array A, in order to find a number higher by the dif.
        {
            while ((itA != setA.end()) && (itB != setB.end()))
            {
                if (*itA - *itB < dif)
                    itA++;
                else if (*itA - *itB > dif)
                    itB++;
                else
                    return 1;
            }
            return -1;
        }
        else
        {
            dif *= -1;
            while ((itA != setA.end()) && (itB != setB.end()))
            {

                if (*itB - *itA < dif)
                    itB++;
                else if (*itB - *itA > dif)
                    itA++;
                else
                    return 1;
            }
            return -1;
        }

        return 0;
	}

/*
1
7 4
4 1 2 1 1 2 6
3 6 3 3
*/


 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends