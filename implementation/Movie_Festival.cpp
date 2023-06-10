#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

bool cmp(pi a, pi b)
{
    if(a.second != b.second) return b.second > a.second;
    else a.first > b.first;
}

void solve()
{
    int n; cin >> n;
    vpi movies;
    fo(i,0,n-1)
    {
        int st, end; cin >> st >> end;
        movies.pb({st,end});
    }
    sort(all(movies), cmp);

    int cnt = 1;
    int ending = movies[0].second;
    fo(i,1,n-1)
    {
        if(ending <= movies[i].first)
        {
            cnt++;
            ending = movies[i].second;
        }
    }
    cout << cnt ;
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}