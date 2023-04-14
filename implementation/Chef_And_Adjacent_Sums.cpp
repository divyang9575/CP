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
    int n; cin >> n;

    int a[n]; fo(i,0,n-1) cin >> a[i];

    sort(a, a+n);
    
    int z = a[n-1] + a[n-2];

    bool flag = true;
    int s = 0;
    int e = n-1;
    while(s<e)
    {
        if(a[s] + a[e] >= z)
        {
            flag = false;
        }
        s++; e--;
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";
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