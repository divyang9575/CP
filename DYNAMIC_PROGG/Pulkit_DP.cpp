// #include<bits/stdc++.h>
// using namespace std;

// const int INF = 2e9;

// int main(){
//     int n; cin >> n;
//     vector<vector<int>> A(n, vector<int>(2));

//     for(int i=0; i<n; i++){
//         cin >> A[i][0] >> A[i][1];
//     }

//     // int max_time = 0;
//     // for(int i=0; i<n; i++){
//     //     max_time = max(max_time, A[i][0]);
//     // }

//     vector<int> prev_dp(2*4003 + 1, -INF), cur_dp(2*4003 + 1, -INF);

//     prev_dp[4000] = 0;

//     for(int i=0; i<n; i++){
//         for(int time=0; time<=2*4000; time++){
//             if(prev_dp[time] == -INF) continue;
            
//             if(time + A[i][0] <= 2*4001)
//                 cur_dp[time + A[i][0]] = max(cur_dp[time + A[i][0]], prev_dp[time]);
            
//             if(time - 1 >= 0)
//                 cur_dp[time - 1] = max(cur_dp[time - 1], prev_dp[time] + A[i][1]);
//         }
//         prev_dp.swap(cur_dp);
//         fill(cur_dp.begin(), cur_dp.end(), -INF); 
//     }

//     int ans = *max_element(prev_dp.begin(), prev_dp.end());
//     cout << ans << endl;

//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n; cin >> n;
    vector<vector<int>> A(n, vector<int>(2));

    for(int i=0; i<n; i++){
        cin >> A[i][0] >> A[i][1];
    }

    // Find max_time to avoid negative indexing.
    // int max_time = 0;
    // for(int i=0; i<n; i++){
    //     max_time = max(max_time, A[i][0]);
    // }
    
    // Initialize dp table with dimensions [n+1][2*max_time+1]
    // to accommodate all possible time values from -max_time to max_time.
    vector<vector<int>> dp(n+1, vector<int>(2*4000+1, -INF));

    // Base case: no luck required for the no-task scenario
    dp[0][4000] = 0; // Shifted time indexing to avoid negative index

    // Bottom-up DP: fill the table from smaller to larger subproblems
    for(int i=0; i<n; i++){
        for(int time=0; time<=2*4000; time++){
            // Continue if current dp state is invalid
            if(dp[i][time] == -INF) continue;
            
            // Option 1: badluck
            if(time + A[i][0] <= 2*4000)
                dp[i+1][time + A[i][0]] = max(dp[i+1][time + A[i][0]], dp[i][time]);
            
            // Option 2: destroy
            if(time - 1 >= 0)
                dp[i+1][time - 1] = max(dp[i+1][time - 1], dp[i][time] + A[i][1]);
        }
    }

    // Find the maximum value in the last row of the dp table
    int ans = *max_element(dp[n].begin(), dp[n].end());
    cout << ans << endl;

    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;

// const long long INF = 1e11;
// const int N = 4e3 + 5;
// // int dp[N][N];

// // long long f(int i, int time, vector<vector<int>> A, int n ){
// //     if(i == n && time >= 0) return 0;
// //     if(i == n && time < 0) return -INF;
// //     if(dp[i][time + (int)2e3] != -1) return dp[i][time + (int)2e3];




// //     long long badluck = f(i+1, time + A[i][0], A, n);
// //     long long destroy = f(i+1, time-1, A, n) + A[i][1];

// //     return dp[i][time + (int)2e3] = max(badluck, destroy);

// // int f(vector<vector<int>> &A, int n){

// //     vector<vector<long long>> dp(n + 1, vector<long long>(8010, -1));

// //     for (int j = 0; j <= 8000; j++) {
// //         dp[n][j] = (j - 4000 >= 0) ? 0 : -INF;
// //     }

// //     for (int i = n - 1; i >= 0; i--) {
// //         for (int time = -2000; time <= 2000; time++) {
// //             long long badluck = dp[i + 1][time + A[i][0] + 4000];
// //             long long destroy = (time - 1 >= -4000) ? (dp[i + 1][time - 1 + 4000] + A[i][1]) : -INF;
// //             dp[i][time + 4000] = max(badluck, destroy);
// //         }
// //     }

// //     return dp[0][4000];
// }
// int main(){
//     int n; cin >> n;
//     vector<vector<int>> A(n, vector<int>(2));

//     for(int i=0; i<n; i++){
//         cin >> A[i][0] >> A[i][1];
//     }
//     // memset(dp, -1, sizeof dp);

//     // int ans = f(0, 0, A, n);
//     int ans = (A, n);
//     cout << ans << endl;
// }

