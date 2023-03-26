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
    int t;
    cin >> t;
    while(t--){
        string str;
        cin>> str;

        set<int> s;
        fo(i,0,3) s.insert(str[i]);

        int count = 0;
        for(auto elem: s){
            count++;
        }

        if(count == 1) cout<<-1<<endl;
        else if(count == 2){
            int c1 = 1;
            int c2 = 0;
            int temp1 = str[0];
            int temp2;
            fo(i,1,3) {
                if(str[i] == temp1){
                    c1++;
                }
                else if(c2 == 0){
                    temp2 = str[i];
                    c2++;
                }
                else if(c2>0 && str[i] == temp2){
                    c2++;
                }
            }

            if(c1 == 2 && c2 == 2) cout << 4 << endl;
            else cout << 6 << endl;
        }
            
        else if(count == 3 || count == 4) cout << 4 << endl;
        else cout << -1<< endl;

    }
    return 0;
}