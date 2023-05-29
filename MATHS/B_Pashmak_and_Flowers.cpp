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
    int n; cin >> n;
    int b[n]; fo(i,0,n-1) cin >> b[i];

    int mxCnt = 0, mnCnt = 0;
    int maxi = *max_element(b, b + n), mini = *min_element(b, b + n);

    int maximalDiff = maxi - mini;

    if(maximalDiff == 0)
    {
        cout << 0 << " " << ( n*(n-1) )/ 2;
        return;
    }

    fo(i,0,n-1)
    {
        if(b[i] == maxi) mxCnt++;

        if(b[i] == mini) mnCnt++;
    }

    cout << maximalDiff <<" " << mxCnt*mnCnt;
}

int32_t main()
{fast
    solve();
    return 0;
}