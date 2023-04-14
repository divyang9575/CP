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

void solve()
{
    int n; cin >> n;

    if(n == 1 || n == 2)
    {
        cout << 0 << endl;
        return;
    }

    if(n&1)
    {
        int move2 = 0;
        if(n > 3){
            move2 = n-1-3;
            move2 = move2/2;
            move2 = move2 + 1;
        }

        int move1 = 0;
        move1 = n-3;
        move1 = move1/2;
        move1++;
        move1++;

        cout << move1 + 2*move2 << endl;

    }
    else 
    {
        n = n - 1;
        int move2 = 0;
        if(n > 3){
            move2 = n-1-3;
            move2 = move2/2;
            move2 = move2 + 1;
        }

        int move1 = 0;
        move1 = n-3;
        move1 = move1/2;
        move1++;
        move1++;
        move1++;
        
        cout << move1 + 2*move2 << endl;

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