// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int amt) 
	{ 
	   
        int dp[n+1][amt+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=amt;j++){
                if(i==0 && j==0)dp[i][j]=INT_MAX-1;
                else if(i==0)dp[i][j]=INT_MAX-1;
                else if(j==0)dp[i][j]=0;
                else if(j>=coins[i-1]){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][amt]==INT_MAX || dp[n][amt]==INT_MAX-1)return -1;
        return dp[n][amt];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends