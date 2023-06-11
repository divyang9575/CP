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


bool ok(int time, int a, int b, int n)
{
    int items = 0;
    items += time / a;
    time -= a; // time for one copy
    items += time / b;

    return items >= n;
}
void solve()
{
    int n, a, b; cin >> n >> a >> b;
    
    int s = 1, e = max(a, b) * n, m;
    while(s+1 < e)
    {
        m = e-(e-s)/2;
        if(ok(m, min(a,b), max(a,b) , n ))
        {
            e = m;
        }
        else s = m;
    }
    cout << e;
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