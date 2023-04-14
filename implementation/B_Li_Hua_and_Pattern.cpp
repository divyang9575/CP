#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define lli long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

const int N = 1e3 + 1;
int mat[N][N];

void solve()
{
    int n,k; cin >> n >> k;

    fo(i,1,n) fo(j,1,n) cin >> mat[i][j] ;

    int count = 0;

    fo(i,1,n) 
    {
        fo(j,1,n)
        {
            if(mat[i][j] != mat[n+1-i][n+1-j])
            {
                count++;
            }
        }
    } 

    count /= 2;

    if(count > k)
    {
        cout << "NO\n";
    }
    else
    {
        if(n&1 == 1 )
        {
            cout << "YES\n";
        }
        else if((k-count)&1 ) {
            cout << "NO\n";
        }
        else
            cout << "YES\n";
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