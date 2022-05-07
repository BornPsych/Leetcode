// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>>dp;
    int solve(vector<int>arr, int sum,vector<vector<int>> &dp,int n){
        if(sum==0){return 1;}
        if(n<=0 || sum<0){return 0;}
        if(dp[n-1][sum]!=-1)return dp[n-1][sum];
        if(arr[n-1]<=sum){
            return dp[n-1][sum] = (solve(arr,sum-arr[n-1],dp,n-1) || solve(arr,sum,dp,n-1));
        }else{
            return dp[n-1][sum] = solve(arr,sum,dp,n-1);
        }
    }

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        for(int i=0;i<=n;i++){
            vector<int>temp;
            for(int j=0;j<=sum;j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        return solve(arr,sum,dp,n);
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