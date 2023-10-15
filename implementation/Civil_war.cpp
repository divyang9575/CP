#include<bits/stdc++.h>
using namespace std;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

const int INF = 1e18 ;
int f(int i, int j, int sum1, int sum2, int turn, vi &arr, int n){
    if(i > j) {
        return abs(sum1 - sum2) ;
    }

    int ans = INF ;
    if(turn == 1){
        ans = min( arr[j] - f(i, j-1, 0, arr, n) , arr[i] - f(i+1, j, 0, arr, n) );
    }
    else{
        ans = min( arr[j] + f(i, j-1, 1, arr, n) , arr[i] + f(i+1, j, 1, arr, n)) ;
    }
    return ans ;
}

void solve()
{
    int n; cin >> n;
    vi arr(n); 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int ans = f(0, n-1, 1, arr, n) ;
    cout << ans << endl;
    

}

int32_t main()
{fast

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}