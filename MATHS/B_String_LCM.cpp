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
    string s,t; cin >> s >> t;

    int slen = s.length();
    int tlen = t.length();
    
    string temp1 = s;
    string temp2 = t;

    if(slen % tlen == 0)
    {
        int fac = slen / tlen;
        while(fac > 1)
        {
            t += temp2;
            fac--;
        }
        if(s == t)
        {
            cout << s << endl;
            return;
        }
        else {cout << -1 << endl; return; }
    }    
    if(tlen % slen == 0)
    {
        int fac = tlen / slen;
        while(fac > 1)
        {
            s += temp1;
            fac--;
        }
        if(s == t)
        {
            cout << s << endl;
            return;
        }
        else{ cout << -1 << endl; return; }
    }    

    int g = __gcd(slen, tlen);            // DECREASED THE RUNTIME (OPTIMIZED)
    
    for(int i = slen / g; i > 1; i--)
    {
        t += temp2;
    }
    for(int i = tlen / g; i > 1; i--)
    {
        s += temp1 ;
    }
    if( s == t)
    {
        cout << s << endl;
    }
    else cout << -1 << endl;
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