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
    int a, b; cin >> a >> b;
    
    int total =  a+b;
    if(total % 3 != 0)
    {
        cout << "NO\n";
        return;
    }

    int mn = total / 3;
    if(min(a, b) < mn)
    {
        cout << "NO\n";
    }else cout << "YES\n";

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