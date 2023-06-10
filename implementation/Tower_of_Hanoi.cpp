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
vpi ans;
void f(int n, int i, int d, int h)
{
    if(n == 1)
    {
        ans.pb({i, d});
    }
    else{
        f(n-1, i, h, d);
        ans.pb({i, d});
        f(n-1, h, d, i);
    }
}

void solve()
{
    int n; cin >> n;
    f(n, 1, 3, 2);
    cout << ans.size() << endl;
    
    for(auto it : ans)
    {
        cout << it.first << " " << it.second << endl;
    }

    
}

int32_t main()
{fast
    solve();
    return 0;
}