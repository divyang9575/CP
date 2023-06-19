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
    int n; cin >> n;
    vi a(n); fo(i,0,n-1) cin >> a[i];
    
    int i = 1;
    int prev = a[0];
    vi ans;
    ans.pb(1);
    while(i < n)
    {
        if(prev <= a[i])
        {
            prev = a[i];
            ans.pb(1);
        }
        else if(a[i] <= a[0]) 
        {
            ans.pb(1);
            prev = a[i];
            i++;
            break;
        }
        else ans.pb(0);
        i++;
    }
    
    while( i < n ) 
    {
        if(a[i] <= a[0] && prev <= a[i])
        {
            prev = a[i]; 
            ans.pb(1);
        }
        else ans.pb(0);
        i++;
    }

    for(auto it : ans) cout << it ;
    cout << endl;
}

int32_t main()
{fast
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}