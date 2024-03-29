// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
	public:
	int perfectSum(int arr[], int n, int sum)
{
       // code here 
       long long m = 1e9 + 7;
       int dp[n+1][sum+1];
       for(int i=0 ;i<n+1;i++){
           for(int j=0 ;j<sum+1 ;j++){
               if(i==0 and j==0){
                   dp[i][j]=1;
               }
               else if(i==0){
                   dp[i][j]=0;
               }
               else if(arr[i-1]<=j){
                   dp[i][j]= (dp[i-1][j-arr[i-1]]%m + dp[i-1][j]%m)%m;
               }
               else{
                   dp[i][j]= dp[i-1][j]%m;
               }
           }
           
       }

       return dp[n][sum];
}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends