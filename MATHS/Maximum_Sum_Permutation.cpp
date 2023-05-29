#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void solve()
{
    int n, q;
    cin >> n >> q;

    vi a(n); fo(i,0,n-1) cin >> a[i];

    vpi send;

    fo(i,0,n-1)
    {
        send.push_back({0,0});
    }

    vector<pair<int , int>> queries;
    fo(i,0,q-1)
    {
        int L, R; cin >> L >> R;
        queries.pb({L,R});
        send[L-1].first++;
        send[R-1].second++;
    }

    int cnt = 0;

    vpi counter;

    fo(i,0,n-1)
    {
        cnt += send[i].first; // queries staring from this index

        counter.pb({cnt, i});

        cnt -= send[i].second; // queries ended at this index
    }

    sort(counter.begin(), counter.end(), greater<>());
    sort(a.begin(), a.end(), greater<>());


    vi ans(n);
    int sum = 0;
    fo(i,0,n-1)
    {
        ans[counter[i].second] = a[i];
        sum += counter[i].first * a[i];
    }

    // vi prefixsum(n+1);
    // prefixsum[0] = 0;

    // fo(i,1,n)
    // {
    //     prefixsum[i] = prefixsum[i-1] + ans[i-1];
    // }
    // fo(i,0,q-1)
    // {
    //     sum += prefixsum[queries[i].second] - prefixsum[queries[i].first-1];
    // }
    cout << sum << endl;

    for(auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
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