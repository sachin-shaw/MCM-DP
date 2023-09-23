//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    int solve(int s , int e , vector<int>&nums){
        if(s>e) return 0;
        if(s == e ) return nums[e-1]*nums[e]*nums[e+1];
       
        int ans=INT_MIN;
        for( int k=s ; k<=e ; k++ ){
            ans = max(ans , solve(s,k-1,nums)+(nums[s-1]*nums[k]*nums[e+1])+solve(k+1,e,nums));
        }
       
        return ans ;
    }
    
    int solveMem( int s , int e , vector<int>&nums , vector<vector<int>>& dp){
        if(s>e) return 0;
        if(s == e ) return nums[e-1]*nums[e]*nums[e+1];
       
        if(dp[s][e]!=-1) return dp[s][e];  //dp state: max collection in [s,e] range
       
        dp[s][e] = INT_MIN;
        for( int k=s ; k<=e ; k++ ){
            dp[s][e] = max(dp[s][e] , solveMem(s,k-1,nums,dp)+(nums[s-1]*nums[k]*nums[e+1])+solveMem(k+1,e,nums,dp));
        }
       
        return dp[s][e] ;
    }
    
    int solveTab(int N, vector<int> &arr){
        //Inserting 1 at the beginning and end of the array.
        arr.insert(arr.begin(), 1);
        arr.push_back(1);

        //Creating a 2D DP array.
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        //Iterating for different lengths of subarrays.
        for (int len = 1; len <= N; ++len)
        {
            //Iterating over all possible subarrays of length len.
            for (int left = 1; left <= N - len + 1; ++left)
            {
                int right = left + len - 1;

                //Iterating over all possible balloons to burst last.
                for (int k = left; k <= right; ++k)
                {
                    //Calculating the maximum number of coins that can be obtained
                    //by bursting balloons from left to right.
                    dp[left][right] = max(dp[left][right], arr[left - 1] * arr[k] * arr[right + 1] + dp[left][k - 1] + dp[k + 1][right]);
                }
            }
        }
        //Returning the maximum number of coins.
        return dp[1][N];
    }
public:
    //Function to find the maximum number of coins that can be obtained.
    int maxCoins(int N, vector<int> &arr)
    {
        // recursion approach---------------------------
        // vector<int> nums;
        // arr.push_back(1) ; 
        // for(int &i:arr) nums.push_back(i); nums.push_back(1);
        // return solve( 1 , N , nums );
        
        // memoization approach--------------------------
        vector<vector<int>> dp(N+1 , vector<int>(N+1 , -1));
        vector<int> nums;
        arr.push_back(1) ; 
        for(int &i:arr) nums.push_back(i); nums.push_back(1);
        return solveMem( 1 , N , nums , dp);
        
        
        //return solveTab(N, arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
