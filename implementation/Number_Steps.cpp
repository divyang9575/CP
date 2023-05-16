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
    int a,b; cin >> a >> b;

    if(a == b)
    {
        if(a&1)
        {
            cout << a+b-1 << endl;
        }
        else{
            cout << a+b << endl;
        }
    }
    else if(b == a-2)
    {
        if(a&1)
        {
            cout << a+b-1 << endl;
        }
        else{
            cout << a+b << endl;
        }
    }
    else{
        cout << "No Number\n";
    }
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