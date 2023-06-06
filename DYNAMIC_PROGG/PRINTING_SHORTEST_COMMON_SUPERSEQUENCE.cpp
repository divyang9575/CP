#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define a(all) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 

int dp[1005][1005];

int SCS(string str1, string str2) {
    int n = str1.length();
    int m = str2.length();

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j<=m; j++)
        {
            //initialize
            if(i == 0) dp[i][j] = j;
            if(j == 0) dp[i][j] = i;

            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

string shortestCommonSupersequence(string s1, string s2)
{
    int lengthOfSCS = SCS(s1, s2);
    int n = s1.length();
    int m = s2.length();

    //traverse through the matrix
    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            i--, j--;
        }
        else
        {
            if(dp[i-1][j] > dp[i][j-1])
            {
                ans += s2[j-1]; // maximum wale ko utha liya minimum ki side chalo
                j--;
            }
            else
            {
                ans += s1[i-1];
                i--;
            }
        }
    }

    while(i == 0 && j > 0)
    {
        ans += s2[j-1]; j--;
    }
    while(j == 0 && i > 0)
    {
        ans += s1[i-1]; i--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

void solve()
{
    string s, t; cin >> s >> t;

    cout << shortestCommonSupersequence(s, t);
}

int32_t main()
{fast
    solve();
    return 0;
}