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

    int a[n];
    fo(i,0,n-1) cin >> a[i];

    long long sum = a[n-1];
    int maxchoc = a[n-1] - 1;

    rfo(i,n-2,0)
    {

        if(a[i] <= maxchoc){
            sum += a[i];
            maxchoc = a[i] - 1;
        }

        else if(a[i] > maxchoc){
            sum += maxchoc;
            maxchoc--;
        }

        if(maxchoc <= 0) break;
    }

    cout << sum;
}

int main()
{fast
   solve();
    return 0;
}