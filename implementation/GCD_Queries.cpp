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

    multiset <int > s;
    fo(i,0,n-1){
        int val;
        cin >> val;
        s.insert(val);
    } 

    int q; cin >> q;
    int query[q];
    fo(i,0,q-1) cin >> query[i];

    for(int x = 0; x<q; x++)
    {
        for(auto it = s.begin(); it != s.end(); it++)
        {
            int gc = __gcd(query[x], (*it));

            if(gc > 1){
                cout << *it << " "; 
                s.erase(it);
                break;
            }

            if(it  == --s.end()){
                cout << *s.begin() << " ";
            }
        }
    }


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