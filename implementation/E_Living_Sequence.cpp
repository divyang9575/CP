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

const lli N = 1e7 + 10;
const lli N2 = 1e5 + 10;
lli a[N];
lli b[N2];

bool check(lli n)
{
    while(n > 0)
    {
        int dig = n%10;

        if(dig == 4)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{fast
    int t;
    cin >> t;

    lli num = 1;
    lli i = 0;
    while(i < N)
    {
        if(check(num))
        {
            a[i] = num;
            num++;
            i++;
        }
        else{
            num++;
        }
    }
    while(i < N2)
    {
        if(check(num))
        {
            b[i] = num;
            num++;
            i++;
        }
        else{
            num++;
        }
    }

    while(t--){
        lli k;  
        cin >> k;

        if(k < N) cout << a[k-1] << endl;

        else{
            cout << b[k-N] << endl;
        }
    }
    return 0;
}