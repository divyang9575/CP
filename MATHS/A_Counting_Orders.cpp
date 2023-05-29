#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
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

bool check(int *a, int *b, int n)
{
    fo(i,0,n-1)
    {
        if(a[i] <= b[i])
            return false;
    }

    return true;
}

bool sorted(int *a, int n)
{
    fo(i,0,n-1)
    {
        if(a[i] > a[i+1]) return false;
    }
    return true;
}

void solve()
{
    int n; cin >> n;
    int a[n],b[n];
    fo(i,0,n-1) cin >> a[i];
    fo(i,0,n-1) cin >> b[i];

    bool flag = false;
    if(check(a, b, n) == true)
    {
        flag = true;
    }
    if(sorted(a,n)) flag = false;

    sort(a, a+n), sort(b, b+n);

    if(check(a, b, n) == false)
    {
        cout << 0 << endl;
        return;
    }

    int ans = 1;
    int pos = 1;
    int i = 0;
    int cnt = 1;
    while(pos < n && i < pos)
    {
        if(b[pos] < a[i])
        {
            cnt++;
            pos++;
            
            if(pos == n) 
            {
                while(cnt > 1)
                {
                    ans *= cnt; cnt--;
                }
            }
        }
        else{
            ans *= pos-i;
            cnt = 1;
            i++;
        }
     }
    if(flag) ans--;

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