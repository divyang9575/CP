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
    int n, k; cin >> n >> k;

    if(k > n / 2)
    {
        cout << "NO\n";
        return;
    }

    if(n % 2  == 0)
    {
        int sets = n / 2;

        int remElem = sets % k;

        if(remElem % 2 == 0)
        {
            cout << "YES\n";
            return;
        }
        else{
            cout << "NO\n";
            return;
        }

    }
    else
    {
        int oddcnt = (n / 2) + 1;

        if(oddcnt % 2 == 0 && k % 2 == 0)
        {
            cout << "YES\n";
            return;
        }
        else {
            cout << "NO\n";
            return;
        }
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