#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define nl '\n'
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int, int>>
#define pb push_back
#define pi pair<int, int>
#define ff first
#define ss second
#define fo(i, s, e) for (int i = s; i <= e; i++)
#define rfo(i, e, s) for (int i = e; i >= s; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);


// binary search ? dp ? change observation..
// edge cases ? overflow ? limits ?

int power(int a,int p=M-2){
	if(p<0) return 0;
	int res=1;
	while(p>0){
		if(p&1) res=(res*a)%M;
		p=p>>1; a=(a*a)%M;
	}
	return res;
}

void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int ls = 0, l4 = 0, l0 = 0;
    int rs = 0, r4 = 0, r0 = 0;
    fo(i, 0, n-1)
    {
        rs += str[i] == '*';
        r4 += str[i] == '4';
        r0 += str[i] == '0';
    }
    int ans = 0;
    fo(i, 0, n-1)
    {
        rs -= (str[i] == '*');
        r4 -= (str[i] == '4');
        r0 -= (str[i] == '0');

        if (str[i] == '0' || str[i] == '*')
        {
            // 4 0 4
            ans += (l4 * r4) % M * power(2, rs + ls);
            ans %= M;

            // 4 0 *
            ans += (l4 * rs) % M * power(2, rs + ls - 1);
            ans %= M;

            //* 0 4
            ans += (ls * r4) % M * power(2, rs + ls - 1);
            ans %= M;

            //* 0 *
            ans += (ls * rs) % M * power(2, rs + ls - 2);
            ans %= M;
        }
        ls += str[i] == '*';
        l4 += str[i] == '4';
        l0 += str[i] == '0';
    }
    cout << ans << nl;
}

int32_t main()
{
    fast
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}