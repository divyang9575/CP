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
    string s; cin >> s;

    string ans = "";
    ans += s[0];
    int cnt = 1;

    for(int i=1; i < n; i++)
    {
        if(s[i] == s[i-1])
        {
            cnt++;
            if(cnt < 3) ans += s[i];
        }
        else{
            cnt = 1;
            if(s[i] == s[i-2] && i-2 >= 0)
                continue;
            else
                ans += s[i];
        }
    }
    // cout << ans << endl;
    cout << ans.size() - 1 << endl;
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