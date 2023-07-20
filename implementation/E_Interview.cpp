#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define memset(dp) memset(dp , -1, sizeof(dp))
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)


 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];
    vi pre(n+1);
    pre[0] = 0;
    fo(i,1,n){
        pre[i] = pre[i-1] + a[i-1];
    }

    int lo = 1, hi = n, mid, ans = -1;
    while(lo <= hi){
        mid = (lo + hi)/2;
        cout << "? " << mid-lo+1 << " ";
        fo(i,lo,mid){
            cout << i << " ";
        }
        cout << endl;
        cout << flush;
        
        int sum ; cin >> sum;
        if(sum > pre[mid] - pre[lo - 1]){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout << "! " << ans << nl << flush;
}

int32_t main(){

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}