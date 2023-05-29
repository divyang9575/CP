// #include<bits/stdc++.h>
// using namespace std;

// #define PI 3.1415926535897932384626433832795
// #define endl '\n'
// #define int long long int
// #define vi vector<int>
// #define sort(a,all) sort(a.begin(), a.end())
// #define vpi vector<pair<int,int>>
// #define pb push_back
// #define pi pair<int,int>
// #define ff first
// #define ss second
// #define fo(i,s,e) for(int i=s; i<=e; i++)
// #define rfo(i,e,s) for(int i=e; i>=s; i--)
// #define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

// void solve()
// {
//     string st; cin >> st;

//     int b, s , c; cin >> b >> s >> c;
//     int bdolar, sdolar, cdolar; cin >> bdolar >> sdolar >> cdolar;
//     int rubles; cin >> rubles;

//     unordered_map< char, int> recipe = {{'B',0}, {'S', 0}, {'C', 0}};
//     for(auto it : st)
//     {
//         recipe[it]++;
//     }

//     // the number we can make from kitchen
//     int ans = 0;
//     int bread = INT_MAX, sausage = INT_MAX, cheese = INT_MAX;
//     if(recipe['B'] > 0)
//     bread = b / recipe['B'];
//     else b = 0;

//     if(recipe['S'] > 0)
//     sausage = s / recipe['S'];
//     else s = 0;

//     if(recipe['C'] > 0)
//     cheese = c / recipe['C'];
//     else c = 0;

//     ans = min(min(bread, sausage) , cheese);

//     // leftover material
//     if(bread != INT_MAX)
//     b -= ans * recipe['B'];

//     if(sausage != INT_MAX)
//     s -= ans * recipe['S'];

//     if(cheese != INT_MAX)
//     c -= ans * recipe['C'];

//     // buy new material
//     int rubal = 0;

//     while(rubles > 0)
//     {
//         if( b == 0 && s == 0 && c == 0)
//         {
//             int total = bdolar * recipe['B'] + sdolar * recipe['S'] + cdolar * recipe['C'];
//             ans += rubles / total;
//             cout << ans ;
//             return;
//         }

//         if(b < recipe['B'])
//         {
//             rubal += bdolar * (recipe['B'] - b);
//             b = 0;
//         }
//         else b -= recipe['B'];

//         if(s < recipe['S'])
//         {
//             rubal += sdolar * (recipe['S'] - s);
//             s = 0;
//         }
//         else s -= recipe['S'];

//         if(c < recipe['C'])
//         {
//             rubal += cdolar * (recipe['C'] - c);
//             c = 0;
//         }
//         else c -= recipe['C'];

//         if(rubal > rubles)
//         {
//             cout << ans ;
//             return;
//         }

//         // else
//         rubles -= rubal;
//         rubal = 0;
//         ans++;
//         if(rubles == 0)
//         {
//             cout << ans;
//         }
//     }

// }

// int32_t main()
// {fast
//     solve();
//     return 0;
// }

// OPTIMAL SOLUTION USING BINARY SEARCH.....

#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define int long long int
#define vi vector<int>
#define sort(a, all) sort(a.begin(), a.end())
#define vpi vector<pair<int, int>>
#define pb push_back
#define pi pair<int, int>
#define ff first
#define ss second
#define fo(i, s, e) for (int i = s; i <= e; i++)
#define rfo(i, e, s) for (int i = e; i >= s; i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

void solve()
{
    string st;
    cin >> st;

    int b, s, c;
    cin >> b >> s >> c;
    int bdolar, sdolar, cdolar;
    cin >> bdolar >> sdolar >> cdolar;
    int rubles;
    cin >> rubles;

    int cntb = 0, cnts = 0, cntc = 0;
    for (auto it : st)
    {
        if (it == 'B')
            cntb++;
        if (it == 'S')
            cnts++;
        if (it == 'C')
            cntc++;
    }

    int ans = 0;
    int start = 0, end = 100000000000000 ;
    while (start <= end)
    {
        int mid = end - (end - start) / 2;  // max number of hamburgers
        
        int bread = max((long long)0, mid * cntb - b);
        int sausage = max((long long)0, mid * cnts - s);
        int cheese = max((long long)0, mid * cntc - c);

        int money = bread * bdolar + sausage * sdolar + cheese * cdolar;

        if (money <= rubles)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans;
}

int32_t main()
{
    fast
    solve();
    return 0;
}