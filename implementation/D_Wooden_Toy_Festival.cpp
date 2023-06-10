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
int n;

bool ok(int time, vi &a)
{
    int cur = -M;
    int carvers = 0;
    for(auto it : a)
    {
        if(abs(it - cur) > time)
        {
            cur = it + time;
            carvers++;
        }
    }
    return (carvers <= 3);
}

void solve()
{
     cin >> n;
     vi a(n); fo(i,0,n-1) cin >> a[i];

    sort(all(a));

    int ans = 0;
    int s = 0, e = 2e9;
    while(s <= e)
    {
        int m = e-(e-s)/2;
        if(ok(m, a))
        {
            ans = m;
            e = m-1;
        }else s = m+1;
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