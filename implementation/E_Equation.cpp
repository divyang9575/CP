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

const double eps = 1e-7;

void solve()
{
    double n; cin >> n;
    cout << fixed << setprecision(15);

    double s = 1, e = 1e6, mid;
    while(e-s > eps)
    {
        mid = e-(e-s)/2;
        if(pow(mid, 2) + pow(mid, 0.5) > n) e = mid;
        else s = mid;
    }
    cout << fixed << setprecision(15) << s ;
    
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