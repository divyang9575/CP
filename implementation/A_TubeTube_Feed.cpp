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
    int n,t;
    cin >> n >> t;

    int a[n+1],b[n+1];

    fo(i,1,n) cin >> a[i];
    fo(i,1,n) cin >> b[i];

    vector<vector<int>> s;

    fo(i,1,n)
    {
        s.pb({b[i], a[i], i});  //entertainment,time,index
    }

    sort(s.begin(), s.end());

    int ans = -1;
    for(int i = s.size()-1; i>=0; i--)
    {
        if(s[i][1] + s[i][2]-1 <= t)
        {
            ans = s[i][2];
            break;
        }
    }

    cout << ans << endl;

}

int main()
{fast
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}