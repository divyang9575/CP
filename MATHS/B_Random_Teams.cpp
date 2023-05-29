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
    int n, m; cin >> n>> m;

    int minPlayers = n / m;
    int remPlayers = n % m;

    int noOfplayers = remPlayers > 0 ? minPlayers + 1 : minPlayers ;

    int minimumPairs = (remPlayers) * (noOfplayers*(noOfplayers - 1) )/ 2 + (m - remPlayers)*(minPlayers*(minPlayers - 1)) / 2;

    int giveOne = n - m;
    int OneTeam = giveOne + 1;

    int maxPairs = (OneTeam * (OneTeam - 1) )/ 2;

    cout << minimumPairs << " " << maxPairs;
}

int32_t main()
{fast
    solve();
    return 0;
}