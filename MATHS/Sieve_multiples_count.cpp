#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a, all) sort(a.begin(), a.end())
#define vpi vector<pair<int, int>>
#define pb push_back
#define pi pair<int, int>
#define ff first
#define ss second
#define fo(i, s, e) for (int i = s; i <= e; i++)
#define rfo(i, e, s) for (int i = e; i >= s; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

const int N = 2e5 + 10;
vector<bool> isPrime(N, true);
vector<int> multiples_cnt(N, 0);

vi hsh(N, 0); // count array

void sieve()
{
  for (int i = 1; i <= N; i++)
  {
    for (int j = i; j <= N; j += i)
    {
      multiples_cnt[i] += hsh[j]; // for eg i = 2, j = 2,4,6,8,10...
    }
  }
}

void solve()
{
  int n;
  cin >> n;
  vi a(n);
  fo(i, 0, n - 1)
  {
    cin >> a[i];
    hsh[a[i]]++; // count of element
  }
  sieve();

  int quer;
  cin >> quer;
  while (quer--)
  {
    int p, q;
    cin >> p >> q;

    long lcm = p * 1LL * q / __gcd(p, q);

    long ans = multiples_cnt[p] + multiples_cnt[q];

    if (lcm < N)
    {
      ans -= multiples_cnt[lcm];
    }

    cout << ans << endl;
  }
}

int32_t main()
{
  fast
  solve();
  return 0;
}