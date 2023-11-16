#include<bits/stdc++.h>
using namespace std;


#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl '\n'
#define M 1000000007
#define PI 3.1415926535897932384626433832795
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

void modsum(int &a, int b) { a = (a%M + b%M + M )%M ;}
void modmul(int &a, int b) { a = (a%M * b%M )%M ;}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const int N = 1e5 + 5;
int dp[25][N];
int n, q;
int arr[N];

int combine(int &a, int &b) {return min(a,b);}

void sparse(){
    for(int j=0; j<n; j++) dp[0][j] = arr[j];

    for(int i=1; i<25; i++){
        for(int j=0; j + (1<<i) <= n; j++){
            // [j, j + 2^i - 1] -> [j, j+2^i-1 - 1] and [j+2^i-1, j+2^i - 1]
            dp[i][j] = combine(dp[i-1][j] , dp[i-1][j + (1<<(i-1))]) ;
        }
    }
}

// int log( int i){
//     return bit_width(i) - 1;
// }

void ckmin(int &mn, int a){
    if(a < mn) mn = a;
}
int lg[N];
void log(){
    for(int i=1; i<N; i++){
        lg[i] = log2(i);
    }
}

int q2(int l, int r){
    int i = lg[r-l+1];
    return min( dp[i][l], dp[i][r - (1<<i) + 1]);
}

// int query(int l, int r){
//     int mn = 1e17;
//     for(int i=24; i>=0; i--){
//         int len = r - l + 1;
//         if((1 << i) <= len){
//             ckmin(mn, dp[i][l]);
//             l += (1<<i);
//         }
//     }
//     return mn;
// }

void solve()
{
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sparse();
    log();
    cin >> q ;
    while(q--){
        int l, r; cin >> l >> r;
        // l--, r--;

        cout << q2(l, r) << endl;

    }
    // cout << log2(1000000);
    
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