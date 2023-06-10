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


void solve()
{
    int n, m , k; cin >> n >> m >> k;
    vi app(n), apar(m);
    fo(i,0,n-1) cin >> app[i];
    fo(i,0,m-1) cin >> apar[i];

    sort(all(app)), sort(all(apar));

    int i = 0, j=0;
    int cnt = 0;
    while(i<n && j<m)
    {
        if(app[i] <= apar[j])
        {
            if(apar[j] - app[i] <= k){
                cnt++;
                i++, j++;
            }
            else{
                i++;
            }
        }
        else{
            if(app[i] - apar[j] <= k)
            {
                cnt++;
                i++, j++;
            }
            else{
                j++;
            }
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