#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
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


void solve()
{
    int w, h, n; cin >> w >> h >> n;
    
    int mn = min(w,h);
    int i = 1;
    int j = n/i;
    int ans = INT_MAX;
    while(j > 0)
    {
        ans = min(ans, max(w*i, j*h));
        i++;
        if(i > n) break;
        j = ceil(double(n)/i);
    }
    cout << ans;
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