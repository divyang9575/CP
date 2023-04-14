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
    int n;
    cin >> n;

    int a[n];
    fo(i,0,n-1) cin >> a[i];

    int x;
    int ans = 0;
    fo(i ,0, n-1)
    {
        ans = ans^a[i];
    }

    if(n%2 == 0){
        ans = ans^0;
        x = 0;
    }
    else {
        x = ans;
        ans = ans^ans;
    }

    if(ans == 0) cout << x << endl;
    else cout << -1 << endl;
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