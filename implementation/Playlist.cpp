#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
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

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    fo(i, 0, n - 1) cin >> a[i];
    set<int> st;              // unordered map got TLE in one test case
    int cnt = 0, mx = 0;

    int start = 0;
    fo(i, 0, n - 1)
    {
        while(st.find(a[i]) != st.end())
        {
            st.erase(a[start]);
            start++;
            cnt--;
        }
        st.insert(a[i]);
        cnt++;
        mx = max(mx, cnt);
    }
    cout << mx;
}

int32_t main()
{
    fast int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}