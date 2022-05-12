// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++
int dp[101][100004];
class Solution{   
public:
    
    bool solve(vector<int>arr, int sum,int n,int dp[][100004]){
        if(sum==0)return true;
        if(sum<0 || n<=0)return false;
        if(dp[n][sum]!=-1)return dp[n][sum];
        if(sum>=arr[n-1]){
            return dp[n][sum] = (solve(arr,sum,n-1,dp) || solve(arr,sum-arr[n-1],n-1,dp));
        }else{
            return dp[n][sum] = solve(arr,sum,n-1,dp);
        }
        
    }
    bool isSubsetSum(vector<int>arr, int sum){
         int n = arr.size();
         memset(dp,-1,sizeof(dp));
         return solve(arr,sum,n,dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends