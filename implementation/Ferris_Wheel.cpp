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
    int n, x; cin >> n >>x;
    vi a(n); fo(i,0,n-1) cin >> a[i];

    sort(all(a));
    int i = 0, j = n-1;
    int cnt = 0;
    while(i<=j)
    {
        if( a[i] + a[j] > x)
        {
            cnt++;
            j--;
        }
        else{
            cnt++;
            i++, j--;
        }
    }
    cout << cnt;
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