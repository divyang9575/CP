#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define lli long long int
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
 
    string s; cin >> s;
    lli n = s.length();

    lli mx = 0;
    lli cnt = 0;
    for(lli i = 0; i <= 2*n - 1; i++)
    {
        if(s[i%n] == '1')
        {
            cnt++;
            mx = max(mx , cnt);
        }
        else cnt = 0;
    }

    if(mx == 2*n)
    {
        mx /= 2;
        cout << mx*1LL*n << endl;
        return;
    }
    if(mx == 1)
    {
        cout << 1 << endl;
        return;
    }

    lli x = 1;
    lli ans = 0;
    while(x < mx)
    {
        ans = max((mx-x)*1LL*(x+1), ans);
        x++;
    }

    cout << ans << endl;


}

int main()
{fast
    lli t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}