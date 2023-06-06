#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int dp[3005][3005];
string s1, s2;

string func(int i, int j)
{

    if(i >= s1.length() || j >= s2.length()) return "";
    string ans = "";
    if(s1[i] == s2[j]) ans += s1[i];

    ans += func(i+1, j);

    ans += func(i, j+1);

    ans += func(i+1, j+1);

    return ans;
}

void solve()
{
    cin >> s1 >> s2;
    memset(dp, -1 , sizeof(dp));

    string ans = "";

    ans += func(0,0);
    cout << ans ;

}

int32_t main()
{fast
    solve();
    return 0;
}