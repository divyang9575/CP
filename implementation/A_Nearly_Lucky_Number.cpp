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

int main()
{
    long long n;
    cin>> n;

    long long count = 0;
    while(n)
    {
        int dig = n%10;

        if(dig == 4 || dig == 7) count++;

        n = n / 10;
    }
    
    bool lucky = true;

    if(count == 0) lucky = false;

    while(count){
        int digit = count%10;
        if(digit != 4 && digit != 7) lucky = false;

        count = count/10;
    }

    if(lucky) cout<<"YES\n";
    else cout << "NO\n";

    return 0;
}