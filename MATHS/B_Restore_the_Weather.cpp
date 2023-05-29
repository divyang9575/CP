#include<bits/stdc++.h>
using namespace std;

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
    int n, k; cin >> n >> k;

    vi predict(n), actual(n); 
    
    fo(i,0,n-1) cin >> predict[i];
    fo(i,0,n-1) cin >> actual[i];

    multimap<int , int > mp;

    vi original(n);
    fo(i,0,n-1)
    {
        original[i] = predict[i];
    }

    sort(predict, all);
    sort(actual, all);

    fo(i,0,n-1)
    {
        mp.insert({predict[i], actual[i]});
    }

    int i = 0;

    while(i<n)
    {
        auto it = mp.find(original[i]);
        cout << it->second << " ";
        mp.erase(it);
        i++;
    }
    cout << endl;
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