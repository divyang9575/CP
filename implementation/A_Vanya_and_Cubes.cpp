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
{fast
    int n;
    cin >> n;

    int sum = 0;
    int count = 0;
    for(int i=1;i<=n;i++){
        if(sum + i*(i+1) / 2 <= n){
            sum += i*(i+1) / 2;
            count++;
        }
        else break;
    }
    cout << count ;
}