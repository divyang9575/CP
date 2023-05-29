#include<bits/stdc++.h>
using namespace std;

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

#define mod 998244353

int fact (int n)
{
    int ans = 1;
    fo(i,2,n)
    {
        ans *= i;   // i % mod does not required because i < mod always 
        ans %= mod;
    }
    return ans;
}
void solve()
{
    int n; cin >> n;

    if(n&1)
    {
        cout << 0 << endl;
        return;
    }

    int oddeven = n / 2;

    int ans = fact(oddeven) % mod;

    cout << (ans*ans) % mod << endl;


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