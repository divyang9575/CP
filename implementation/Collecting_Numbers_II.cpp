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
    int n, m; cin >> n >> m;
    vi a(n + 1); fo(i, 1, n) cin >> a[i];
    
    int pos[n + 1];
    fo(i, 1, n)
        pos[a[i]] = i;

    int cnt = 1;
    int diff[n];
    fo(i, 1, n - 1)
    {
        diff[i] = pos[i+1] - pos[i]; // diff[1] = pos[2] - pos[1]
        if(diff[i] < 0) cnt++;
    }

    while(m-- > 0)
    {
        int p, q; cin >> p >> q;
        int i1 = min(a[p], a[q]), i2 = max(a[p], a[q]); // swaping index in pos array
        
        swap(pos[i1], pos[i2]);

        //update diff array
        int prev1 = diff[i1-1], prev2 = diff[i1], prev3 = diff[i2];
        if(i1 > 1) diff[i1-1] = pos[i1] - pos[i1-1];
                   diff[i1] = pos[i1+1] - pos[i1];
        if(i2 < n) diff[i2] = pos[i2+1] - pos[i2];

        if(prev1 < 0 && diff[i1-1] > 0) cnt--;
        if(prev1 > 0 && diff[i1-1] < 0) cnt++;

        if(prev2 < 0 && diff[i1] > 0) cnt--;
        if(prev2 > 0 && diff[i1] < 0) cnt++;

        if(prev3 < 0 && diff[i2] > 0) cnt--;
        if(prev3 > 0 && diff[i2] < 0) cnt++;

        cout << cnt << endl;
    }
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