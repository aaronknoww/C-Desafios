//{ Driver Code Starts
//Initial Template for C++

//TERMINADO Y CALIFICADO CON 100 GEEK F GEEK SAMSUNG

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C)
    {
        int row = 0;
        int col = 0;
        short dir = 0; // move to: 0-> right, 1-> down, 2-> left, 3-> up   
        
        while (true)
        {
            if(matrix[row][col] == 1)
            {
                // Chage direction required
                matrix[row][col] = 0;
                if(dir >=3 )
                    dir = 0;
                else
                    dir++;
            }

            switch (dir)
            {
                case 0:
                    col++;
                    if(col >= C)
                        return {row, col-1};
                    break;
                case 1:
                    row++;
                    if(row >= R)
                        return { row -1, col};
                    break;
                case 2:
                    col--;
                    if(col < 0)
                        return {row, col+1};
                    break;
                case 3:
                    row--;
                    if(row < 0)
                        return {row+1, col};
                    break;            
                default:
                    break;
            }

        }
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends

/*
1
2 2
0 1
1 0
*/