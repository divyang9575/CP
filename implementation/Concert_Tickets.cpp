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
    int n,m; cin >> n >> m;
    multiset<int> price;
    fo(i,0,n-1) 
    {
        int x ; cin >> x;
        price.insert(x);
    }

    for(int i=0; i<m; i++)
    {
        int boy; cin >> boy;

        auto it = price.upper_bound(boy);

        if(it == price.begin())
        {
            cout << -1 << endl;
        }
        else{
            cout << *(--it) << endl;
            price.erase(it);
        }
    }
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

