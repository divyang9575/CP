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
    int n; cin >> n;

    vector<pair<int , string >> book;
    fo(i,0,n-1)
    {
        int temp; cin >> temp;
        string s; cin >> s;

        book.pb({temp,s});
    }

    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int minb = INT_MAX;
    int ans = -1;

    fo(i,0,n-1)
    {
        if(book[i].second[0] == '0' && book[i].second[1] == '1')
        {
            min2 = min(min2, book[i].first);
        }
        else if(book[i].second[0] == '1' && book[i].second[1] == '0')
        {
            min1 = min(min1, book[i].first);
        }
        else if(book[i].second[0] == '1' && book[i].second[1] == '1')
        {
            minb = min(minb, book[i].first);
        }
    }

    if(min1 != INT_MAX && min2 != INT_MAX )
    {
        if(minb == INT_MAX)
        {
            ans = min1 + min2;
        }
        else{
            ans = min(minb, min1 + min2);
        }
    }
    else if(minb != INT_MAX)
    {
        ans = minb;
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