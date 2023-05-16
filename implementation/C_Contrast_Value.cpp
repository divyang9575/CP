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
    int n; cin >> n;

    vi a(n); fo(i,0,n-1) cin >> a[i];

    // if(n == 2)
    // {
    //     if(a[1] == a[0]){
    //         cout << 1 << endl;
    //         return;
    //     }
    //     else
    //     {
    //         cout << 2 << endl;
    //         return;
    //     }
    // }

    n = unique(a.begin(), a.end()) - a.begin();
    int cnt = n;

    fo(i,1,n-2)
    {
        if(a[i-1] > a[i] && a[i] > a[i+1])
        {
            cnt--;
        }
        if(a[i-1] < a[i] && a[i] < a[i+1])
        {
            cnt--;
        }
    }


    cout << cnt << endl;
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