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

string recep;
int b, s, c;
int pb, ps, pc;
int rubles;
unordered_map<char, int> mp;

bool isPossible(int m)
{
    int needB =  m * mp['B'] - b > 0 ? m * mp['B'] - b : 0 ;
    int needS =  m * mp['S'] - s > 0 ? m * mp['S'] - s : 0 ;
    int needC =  m * mp['C'] - c > 0 ? m * mp['C'] - c : 0 ;

    int money = pb * needB + ps * needS + pc * needC;
    if(money <= rubles) return true;
    else return false;
}

void solve()
{
     cin >> recep;
     cin >> b >> s >> c;
     cin >> pb >> ps >> pc;
     cin >> rubles;

    for(auto it : recep) mp[it]++;

    int st = 0, end = 1e13;
    int ans = 0;
    while(st<=end)
    {
        int mx = end - (end-st)/2;
        if(isPossible(mx))
        {
            ans = mx;
            st = mx + 1;
        }
        else end = mx - 1;
    }
    cout << ans;
}

int32_t main()
{fast
    solve();
    return 0;
}