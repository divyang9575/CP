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
    int frens,botl,litre,lime,slice,sal,needlitre,needsal;

    cin>>frens>>botl>>litre>>lime>>slice>>sal>>needlitre>>needsal;

    int havelitre = botl*litre;

    int haveslice = lime*slice;

    int toast = min (havelitre/needlitre , min(haveslice, sal/needsal));

    int toastEach = toast / frens;

    cout << toastEach << endl;
    
    return 0;
}