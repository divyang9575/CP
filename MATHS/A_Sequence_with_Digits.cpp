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

int adding(int a)
{
    int m2 = 10, m1 = 0;

    while(a > 0)
    {
        int dig = a%10;

        m1 = max(dig, m1);
        m2 = min(dig, m2);

        a /= 10;
    }

    return m1 * m2;
}

void solve()
{
    int a, k; cin >> a >> k;

    int ans = a;

    k--;
    while(k > 0)
    {
        int add = adding(ans);

        if(add == 0) break;

        ans += add;
        k--;
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