#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#define yes cout << "YES" << endl
#define no cout << "NO" << endl

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
	int n; cin >> n;
	vi a(n); fo(i,0,n-1) cin >> a[i];
	
	int g = 0;
	fo(i,0,n-1)
	{
	    g = __gcd(g, a[i]);
	}
	
	fo(i,0,n-1){
	    if(a[i] == g){
	        cout << 1 << " ";
	    }
	    else if(g < a[i]){
	        cout << a[i] / g << " ";
	    }
	    else cout << a[i] << " ";
	}
	cout << nl;
	
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