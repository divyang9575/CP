#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define lli long long int
#define vi vector<lli>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(lli i=s; i<=e; i++)
#define rfo(i,e,s) for(lli i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 1000000;
bool primes[N+10];

void sieve()
{
    primes[0] = false;
    primes[1] = false;

    fo(i,2,N)
    {
        primes[i] = true;
    }   

    for(lli i = 2; (long long)(i*i) <= N; i++)
    {
        if(primes[i])
        {
            for(lli j = (long long)i*i; j<=N; j+=i)
            {
                primes[j] = false;
            }
        }
    }
}

vi prime_dedo(lli n)
{   
    vi ans;

    fo(i,2,n)
    {
        if(primes[i])
        {
            ans.pb(i);
        }
    }
    return ans;
}

vi segmented(lli l, lli r)
{
    lli sq = sqrt(r);

    vi prme = prime_dedo(sq);

    vector<bool> dummy(r-l+1, true);
    for(auto pr: prme)
    {
        lli firstelem = (l/pr) * pr;              // (110/3) = 108
        if(firstelem < l) firstelem += pr;        //  + 3 = 111

        for(lli i = max((long long)pr*pr, firstelem); i <= r; i+=pr)
        {
            dummy[i-l] = false;
        }
    }

    vi ans;
    for(lli i = l; i <= r; i++)
    {
        if(dummy[i-l])
        {
            ans.pb(i);
        }
    }

    return ans;
}

void solve()
{
    lli l,r;
    cin >> l >> r;
    vi okay;
    if(l == 1 && r == 1)
    {
        cout << " " << endl;
        return;
    }
    else if(l == 1)
    {
        okay = segmented(l+1,r);
    }
    else{
        okay = segmented(l,r);
    }

    for(auto it : okay)
    {
        cout << it << endl;
    }
}

int main()
{fast
    sieve();
    int t;
    cin >> t;
    while(t--){
        solve();
        cout << endl;
    }
    return 0;
}