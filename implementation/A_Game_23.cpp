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
    int a,b;
    cin >> a >> b;

    int result = -1;

    if(b%a == 0)
    {
        result = 0;
        int factor = b/a;

        while(factor%2 == 0)
        {
            factor /= 2;
            result++;
        }
        while(factor%3 == 0)
        {
            factor /= 3;
            result++;
        }

        if(factor != 1) result = -1;
    }

    cout << result << endl;
}

int main()
{fast
    solve();
    return 0;
}