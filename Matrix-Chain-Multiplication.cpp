//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int arr[], int n, int i, int j){
        if(i+1 == j){
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int k = i+1; k<j; k++){
            ans = min(ans, solve(arr, n, i, k) + solve(arr, n, k, j) + arr[i]*arr[k]*arr[j]);
        }
        
        return ans;
    }
    
    int solveMem(int arr[], int n, int i, int j, vector<vector<int>> &dp){
        if(i+1 == j){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        dp[i][j] = INT_MAX;
        
        for(int k = i+1; k<j; k++){
            dp[i][j] = min(dp[i][j], solveMem(arr, n, i, k, dp) + solveMem(arr, n, k, j, dp) + arr[i]*arr[k]*arr[j]);
        }
        
        return dp[i][j];
    }
    
    int solveTab(int arr[], int n){
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        for(int i=0; i<n-1; i++){
            dp[i][i+1] = 0;
        }
        
        for(int gap=2; gap<n; gap++){
            for(int i=0; i+gap<n; i++){
                int j = i+gap;
                dp[i][j] = INT_MAX;
                for(int k = i+1; k<j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        //return solve(arr, N, 0, N-1);
        
        //vector<vector<int>> dp(N, vector<int>(N, -1));
        //return solveMem(arr, N, 0, N-1, dp);
        
        return solveTab(arr, N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
