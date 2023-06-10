#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
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


void solve()
{
    int n, k, q; cin >> n >> k >> q;
    int a[n]; fo(i,0,n-1) cin >> a[i];

    vi count;
    int cnt = 0;

    fo(i,0,n-1)
    {
        if(a[i] <= q)
        {
            cnt++;
        }
        else{
            if(cnt > 0) count.pb(cnt);
            cnt = 0;
        }
    }
    if(cnt > 0) count.pb(cnt);

    int ans = 0;
    for(auto it : count)
    {
        if(it < k) continue;
        
        int last = (it + 1) - k;

        ans += (last*(last + 1)) / 2;
    }
    cout << ans << endl;
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