#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(lli i=s; i<=e; i++)
#define rfo(i,e,s) for(lli i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

void solve()
{
    lli n,m;
    cin >> n >> m;

    lli lines[n];
    lli a[m];
    lli b[m];
    lli c[m];

    fo(i,0,n-1) cin >> lines[i];
    fo(i,0,m-1) cin >> a[i] >> b[i] >> c[i];

    sort(lines, lines+n);

    fo(i,0,m-1)
    {
        if(c[i] < 0)
        {
            cout << "NO\n";
            continue;
        }
        
        lli s = 0; lli e = n-1;
        bool flag = false;
        while(s<=e)
        {
            lli mid = e - (e-s)/2;

            if(pow(b[i]-lines[mid], 2) < 4*a[i]*c[i]) // (b-mid)^2 - 4ac < 0 , means no solution.
            {
                cout << "YES\n";
                cout << lines[mid] << endl;
                flag = true;
                break;
            }
            else
            {
                if(b[i] > lines[mid]) // we want absolute difference of b - mid to be minimum
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
        }

        if(!flag) cout << "NO\n";
    }
}

int main()
{fast
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}