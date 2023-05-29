#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
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

    int mx = 1, cnt = 1;
    bool flag = false;

    fo(i,1,n-1)
    {
        if( (s[i] == '<' && s[i-1] == '<') || (s[i] == '>' && s[i-1] == '>'))
        {
            cnt++;
            mx = max(cnt, mx);
        }
        else{
            cnt = 1;
        }
    }

    cout << mx + 1 << endl;
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