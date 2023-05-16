#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
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

    string s; cin >> s;

    for(int i = 0;i<n-1 ; i++)
    {
        if(s[i] != s[i+1])
        {
            cout << "YES\n";
            cout << s[i] << s[i+1] ;
            return;
        }
    }
    cout << "NO";
}

int32_t main()
{fast
    solve();
    return 0;
}