#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
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

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
    int n; cin >> n;
    vpi arr; 
    fo(i,0,n-1)
    {
        int a, b; cin >> a >> b;
        arr.pb({a, b});
    }

    unordered_map<int, priority_queue <int>> mp;

    for(auto it : arr)
    {
        mp[it.first].push(it.second);
    }
    
    int ans = 0;
    for(auto it : mp)
    {
        int elems = it.first;
        while(elems > 0 && !it.second.empty())
        {
            ans += it.second.top();
            it.second.pop();
            elems--;
        }
    }
    cout << ans << endl;
    cout << pow(2,16) <<endl;

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