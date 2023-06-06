#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
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

const int N = 101;
int fact[N];
int inverse(int n, int m)
{
    int power = m-2; // m is prime

    // Binary exponentiation of n^(m-2) % m
    int ans = 1;
    while(power > 0)
    {
        if(power % 2 == 0)
        {
            power /= 2;
            n = (n *1LL* n) % m;
        }
        else 
        {
            ans = (ans *1LL* n) % m;
            power--;
        }
    }
    return ans;
}

void factorials()
{
    fact[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
}

void solve()
{
    factorials();

    int n, k; cin >>n>> k;

    if(k > n) cout << (fact[k] *1LL* inverse(fact[k - n], M)) % M << endl;
    else cout << fact[k] << endl;


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