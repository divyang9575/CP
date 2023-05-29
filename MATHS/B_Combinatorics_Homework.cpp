#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
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
    int a, b ,c, m; cin >> a >> b >> c >> m;

    int maxi = a + b + c - 3;

    int mxElem = max(max(a, b), c);
    int mini =  mxElem - 1 - (a + b + c - mxElem) < 0 ? 0 : mxElem - 1 - (a + b + c - mxElem);

    if(m <= maxi && m >= mini)
    {
        cout << "YES\n";
    }
    else cout << "NO\n";
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