#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 1e5 + 10;
int fact[N];

void factorials()
{
    fact[0] = 1;
    for(int i = 1; i <= N; i++)
    {
        fact[i] = (fact[i-1] * 1LL * i) % M;
    }
}

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

int nCr(int n , int r)
{
    int num = fact[n];
    int den = inverse((fact[n-r] *1LL* fact[r]) % M , M);

    int ans = (num * 1LL * den ) % M;
    return ans;
}

void solve()
{
    int n, k; cin >> n >> k;
    cout << nCr(n,k);
}

int32_t main()
{fast
    int t;
    cin >> t;
    factorials();

    while(t--){
        solve();
    }
    return 0;
}