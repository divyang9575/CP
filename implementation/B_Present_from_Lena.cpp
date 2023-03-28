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

    for(int i = 0; i< 2*n+1; i++)
    {
        int count = 0;
        bool flag = false;
        fo(j,0,4*n)
        {
            if(i <= n){
                if(j >= 2*n - 2*i  && j%2 == 0 && j <= 2*n + 2*i)
                {
                    cout << count;
                    
                    if(flag) count--;
                    else{
                        count++;
                        if(count >= i || i > n) flag = true;
                    }
                }
                else cout << " ";
            }
            else{
                int maxcount = n-1;
                flag = false;
                if(j >= 2*(i-n) && j%2 == 0  ){
                    cout << count;
                    
                    if(count < maxcount && flag == false) count++;
                    else{
                         count--;
                         flag = true;
                    }
                }
                else cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{fast
    solve();

    return 0;
}