#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
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
    int a[n+1]; fo(i,1,n) cin >> a[i];

    int i, j;
    int mx = 0;
    int mxind = 0;
    fo(k,1,n)
    {
        if(a[k] == 1) i = k;
        if(a[k] == 2) j = k;
        if(a[k] > mx)
        {
            mx = a[k];
            mxind = k;
        }
    }

        if(mxind < min(i, j))
        {
            cout << mxind << " " << min(i,j) << endl;
        }
        else if(mxind > max(i, j))
        {
            cout << mxind << " " << max(i,j) << endl;
        }
        else cout << "1 1" << endl;
    
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