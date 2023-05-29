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

void solve()
{
    int x,y,prc; cin >> x >> y >> prc;

    int chic1 = x % prc;
    int chic2 = y % prc;

    int ans = x/prc + y/prc;

    int giver = min(chic1, chic2);
    int want = prc - max(chic1, chic2);

    int borrow = 0;
    if(giver >= want)
    {
        borrow = want;
        ans++;
    }
    cout << ans << " " << borrow;
}

int32_t main()
{fast
    solve();
    return 0;
}