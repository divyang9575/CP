#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
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
    string s; cin >> s;

    string ans = "";
    bool flag = false;
    fo(i,0,n-1)
    {
        if(flag == false)
        {
            ans += s[i];
            flag = true;
        }
        else if(s[i] == ans.back())
        {
            flag = false;
        }
    }
    cout << ans << endl;

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