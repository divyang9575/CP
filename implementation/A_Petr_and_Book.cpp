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
    int n;
    cin >> n;

    int a[7];
    fo(i,0,6) cin >> a[i];

    int day = 0;
    // if(n <= a[0]) cout << 1 << endl;

    {
        int i = 0;
        while(n > 0)
        {
            n = n-a[i];
            i = (i+1)%7;

            if(day < 7) day++;
            else day = 1;
        }
    }
    cout << day << endl;
}

int main()
{fast
    solve();
    return 0;
}