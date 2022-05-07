// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<vector<int>>dp;

    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        for(int i=0;i<=n;i++){
            vector<int>temp;
            for(int j=0;j<=sum;j++){
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
               if(i==0)dp[i][j]=0;
               if(j==0)dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
               if(arr[i-1]<=j){
                   dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
               }else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
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