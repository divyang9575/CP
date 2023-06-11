#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
const double eps = 1e-7;

bool ok(double mxlen, vi& a, int n, int k)
{
    if(mxlen == 0) return true;
    int pieces = 0;
    fo(i,0,n-1)
    {
        int cut = a[i] / mxlen;
        pieces += cut;
    }
    return pieces >= k;
}

void solve()
{
    int n, k; cin >> n >> k;
    vi a(n); fo(i,0,n-1) cin >> a[i];

    double s = 0, e = 1e8, m;
    int lp = 100;
    while((e-s) > eps)
    {
        m = (s+e)/2;
        if(ok(m, a, n, k))
            s = m;
        else 
            e = m;
    }
    cout << setprecision(7) << s ;
    
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