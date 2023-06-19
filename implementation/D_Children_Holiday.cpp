#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 
 
const int N = 1002;
int ass[N];

bool ok(int time, vector<vi> a, int n, int m)
{
    
    fo(i,0,n-1)
    {
        int items = 0;
        int t = a[i][0];
        int z = a[i][1];
        int y = a[i][2];

        int batchTime = t*z + y ;
        int batches = time / batchTime;
        
        if(time % batchTime == 0)
        {
            items += batches * z * t;
        }
        else{
            items += batches * z * t;
            int remTime = time - batches * batchTime;
            if(remTime / t <= z )
            {
                items += (remTime / t) * t;
            }
            else 
            {
                items += z*t;
            }
        }
        ass[i] = items;
    }
    return accumulate(ass, ass+n, 0) >= m;
}

void solve()
{
    memset(ass, 0, sizeof(ass));
    int m,n; cin >> m >> n;
    vector<vi> ar(n, vector<int>(3));
    fo(i,0,n-1)
    {
        cin >> ar[i][0] >> ar[i][1] >> ar[i][2];
    }

    
    int s = 1, e = 1e9, mid;
    while(s+1 < e)
    {
        mid = e-(e-s)/2;
        if(ok(mid, ar, n, m))
        {
            e = m;
        }
        else s = m;
    }
    cout << e << endl;

    fo(i,0,n-1)
    {
        cout << ass[i] <<  " ";
    }
    // cout << endl;
}

int32_t main()
{fast
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}