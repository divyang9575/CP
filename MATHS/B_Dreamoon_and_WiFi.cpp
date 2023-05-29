#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a,all) sort(a.begin(), a.end())
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

int fact(int n)
{
    int ans = 1;
    fo(i,1,n)
    {
        ans *= i;
    }
    return ans;
}

double nCr(int n, int r)
{
    double num = fact(n);
    double den = fact(n-r) * fact(r);

    return num / den;
}

void solve()
{
    string s1, s2; cin >> s1 >> s2;

    int actual = 0;
    int wantsTo = 0;
    int tukka = 0;

    fo(i,0,s1.length()-1)
    {
        if(s1[i] == '+') wantsTo++;
        if(s1[i] == '-') wantsTo--;

        if(s2[i] == '+') actual++;
        if(s2[i] == '-') actual--;

        if(s2[i] == '?') tukka++;
    }

    int totaltukka = tukka;

    if(actual == wantsTo && tukka == 0)
    {
        cout << fixed << setprecision(12) << (double)1 ;
        return;
    }

    int diff = abs(wantsTo - actual);
    bool flag ;

    
    int posORneg = diff;
    if(tukka < posORneg)
        flag = false;
    else{
        tukka -= posORneg;
        if(tukka % 2 == 0)
        {
            flag = true;
            posORneg += tukka / 2;
        }
        else{
            flag = false;
        }
    }

    if(flag)
    {
        double num = nCr(totaltukka, posORneg);
        double den = pow(2, totaltukka);

        cout << fixed << setprecision(12) << num / den;
    }
    else cout << fixed << setprecision(12) << (double)0 ;
    
}

int32_t main()
{fast
    solve();
    return 0;
}