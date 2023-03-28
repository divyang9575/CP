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

    int sum = n;

    int pressed = 1;
    int left = n-1;

    while(left > 0)
    {
        for(int i = 1; i<=left-1 ; i++)
        {
            sum += pressed+1;
        }
        if(left > 1) sum += 1;

        left--;
        pressed++;
    }
    if(n > 1) sum++;

    cout << sum;
}

int main()
{fast
    solve();

    return 0;
}