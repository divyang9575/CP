#include<bits/stdc++.h>
using namespace std;

#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define cntbits(x) __builtin_popcount(x)
#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(a) a.begin(), a.end()
#define precise(i) cout<<fixed<<setprecision(i)
#define take(a,n) for(int j=0;j<n;j++) cin>>a[j]
#define give(a,n) for(int j=0;j<n;j++) cout<<a[j]<<' '; cout << endl;
#define vpi vector<pair<int,int>>
#define pi pair<int,int>

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

set<vector<vector<char>>> ans ;

vector<pi> moves = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}} ;

bool isvalid(int i, int j, int n, vector<vector<int>> &vis){
    if(i < 0 || j < 0 || i >= n || j >= n) return false;

    for(pi move : moves){
        int x = i + move.first, y = j + move.second ;
        if(x < 0 || y < 0 || x >= n || y >= n) continue;

        if(vis[x][y]) return false;
    }

    return true ;
}

void f(int i, int j, int knights, int n, vector<vector<char>> &board, vector<vector<int>> &vis) 
{
    if(knights == 0){
        ans.insert(board) ;
        return ;
    }

    if(i < 0 || j < 0 || i>=n || j>=n) return ;

    if(vis[i][j]) return ;

    if(isvalid(i, j, n, vis))
    {
        for(int a = -2; a<=2; a++) // make a loop from 0 to n-1te
        {
            for(int b = -2; b<=2; b++)
            {
                if(a == 0 && b == 0) continue;

                board[i][j] = 'k'; vis[i][j] = 1;

                f(i+a, j+b, knights-1, n, board, vis) ;

                board[i][j] = '.'; vis[i][j] = 0;
            }
        }
    }

    return ;
}

void solve()
{
    int n, k; cin >> n >> k;

    vector<vector<char>> board(n, vector<char>(n, '.')) ; 
    vvi vis(n, vi(n, 0)) ;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            f(i, j, k, n, board, vis) ;
        }
    }

    // int cnt = 1;
    for(auto bord : ans){
        // cout << cnt++ << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << bord[i][j] ;
            }
            cout << endl;
        }
        cout << endl;
    }
}

int32_t main()
{
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}