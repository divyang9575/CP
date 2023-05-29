#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

vi swapLR(vi a, int l , int r)
{
    int sz = a.size();
    vi ans;

    fo(k, r+1, sz-1) ans.pb(a[k]);
    
    rfo(k,r,l) ans.pb(a[k]);
    
    fo(k,0,l-1) ans.pb(a[k]);

    return ans;
}

void solve()
{
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];

    // EDGE CASE 1
    if(n == 1)
    {
        cout << a[0] << endl;
        return;
    }
    ////

    int mxInd = max_element(a.begin(), a.end()) - a.begin();
    
    // EGDE CASE 2
    if(mxInd == 0)
    {   
        mxInd = max_element(a.begin() + 1, a.end()) - a.begin();
    }
    ////

    vi current; // STORE EVERY POSSIBLE VECTOR
    vi ans = a;
    sort(ans.begin(), ans.end()); // MIN LEXOGRAPHICAL

    // EGDE CASE 3
    if(mxInd == n-1)
    {
        current.pb(a[n-1]);
        int iter = n-2;
        while(a[iter] > a[0])
        {
            current.pb(a[iter]);
            iter--;
        }
        fo(i,0,iter)
        {
            current.pb(a[i]);
        }
        ans = max(ans, current);
    }
    ////

    // NORMAL CASE
    int r = mxInd - 1;
    int l = 0;

    while(l <= r)
    {
        current = swapLR(a, l, r);
        ans = max(ans, current);
        l++;
    }
    
    fo(i,0,n-1)
    {
        cout << ans[i] <<  " ";
    }
    
    cout << endl;
}

int32_t main()
{fast
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}