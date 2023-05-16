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

void solve()
{
    int n,k; cin >> n >> k;
    
    int a[n+1]; fo(i,1,n) cin >> a[i];

    int sum[n+1];
    sum[0] = 0;

    sort(a+1, a+n+1);

    fo(i,1,n)
    {
        sum[i] = sum[i-1] + a[i];
    }

    int ans = 0;
    for(int i = 0; i <= k; i++)
    {
        ans = max(ans, sum[n-k+i] - sum[2*i]);
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