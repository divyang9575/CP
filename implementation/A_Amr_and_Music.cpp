#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
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
    int n,k; cin >> n >> k;

    vpi a;
    int ind = 0;
    fo(i,0,n-1) {
        int temp; cin >> temp;
        ind++;
        a.pb({temp,ind});
    }
    

    sort(a.begin(), a.end());


    int cnt = 0;
    vi ans;
    int sum = 0;
    fo(i,0,n-1)
    {
        if(a[i].first + sum <= k)
        {
            cnt++;
            ans.pb(a[i].second);
            sum += a[i].first;
        }
    }

    cout << cnt << endl;

    for(auto it : ans)
    {
        cout << it << " ";
    }
}

int32_t main()
{fast
    solve();
    return 0;
}