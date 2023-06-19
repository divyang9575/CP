#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define nl '\n'
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
    int n, k; cin >> n >> k;
    string s; cin >> s;

    set<char> st = {'a', 'e', 'i', 'o', 'u'};
    vi ind;
    fo(i,0,n-1)
    {
        if(st.find(s[i]) != st.end())
        {
            ind.pb(i);
        }
    }

    int ans = 1;
    for(int i = k; i<ind.size(); i+=k)
    {
        ans = (ans * (ind[i]-ind[i-1])) % M;
    }
    cout << ans << nl;
}

int32_t main()
{fast
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}