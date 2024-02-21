#include <bits/stdc++.h>
using namespace std;

// Terminado y paso en leet code

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if(rows == 1)
        {
            for(int i = 0; i< cols; i++)
                if(obstacleGrid[0][i] == 1)
                    return 0;
            return 1;
        }
        else if(cols == 1)
        {
            for(int i = 0; i< rows; i++)
                if(obstacleGrid[i][0] == 1)
                    return 0;
            return 1;
        }
        else if(cols == 1 && rows == 1)
        {
            return (obstacleGrid[0][0] == 1) ? 0 : 1;
        }
        
         
        int dp[rows][cols] = {0};

        for(int i = 0; i< cols; i++) // To set 1 in all first row.
        {
            if(obstacleGrid[0][i] == 1)
            {
                for (int x = i; x < cols; x++)
                    dp[0][x] = 0;
                break;                
            }
            dp[0][i] = 1;
        }
        
        for(int i = 0; i < rows; i++) // To set 1 in all first column.
        {
            if(obstacleGrid[i][0] == 1)
            {
                for (int x = i; x < rows; x++)
                    dp[x][0] = 0;
                break;                
            }
            dp[i][0] = 1;
        }
        
        for(int r = 1; r < rows; r++)
        {
            for(int c = 1; c < cols; c++)
            {
                if(obstacleGrid[r][c] == 1)
                    dp[r][c] = 0;
                else
                    dp[r][c] = dp[r-1][c] + dp[r][c-1];
            }
        }

        return dp[rows-1][cols-1];
        
    }
};

int main()
{
    vector<std::vector<int> > fog { {0,0,0},{0,1,0},{0,0,0} };
    Solution ob;
    int res = ob.uniquePathsWithObstacles(fog);
    cout<<res;
    
    /*
    [[0,0,0],[0,1,0],[0,0,0]]
    */
    
    return 0;
}