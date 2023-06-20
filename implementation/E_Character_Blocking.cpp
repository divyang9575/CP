#include<bits/stdc++.h>
using namespace std;

#define M 1000000007
#define PI 3.1415926535897932384626433832795
#define nl '\n'
#define sz(a) a.size()
#define int long long int
#define vi vector<int>
#define all(a) a.begin(), a.end()
#define vpi vector<pair<int,int>>
#define pb push_back
#define pi pair<int,int>
#define ff first
#define ss second
#define fo(i,s,e) for(int i=s; i<=e; i++)
#define rfo(i,e,s) for(int i=e; i>=s; i--)
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

 // binary search ? dp ? change observation.. 
 // edge cases ? overflow ? limits ? 


void solve()
{
    string s1, s2; cin >> s1 >> s2;
    int t, quer; cin >> t >> quer;

    int badpos = 0;
    fo(i,0,sz(s1)-1)
    {
        if(s1[i] != s2[i]) badpos++;
    }

    queue<pair<int, int>> blocked;

    //queries
    fo(i,1,quer)
    {
        if(!blocked.empty() && blocked.front().ss == i)
        {
            int index = blocked.front().ff;
            if(s1[index] != s2[index]) badpos++;

            blocked.pop();
        }

        int qtype; cin >> qtype;
        if(qtype == 3)
        {
            puts((badpos == 0) ? "YES" : "NO");
            continue;
        }

        if(qtype == 1)
        {
            int pos; cin >> pos;
            //put the index in the queue along with unblocking time
            blocked.push({pos-1, i+t});
            if(s1[pos-1] != s2[pos-1]) badpos--;
        }

        if(qtype == 2)
        {
            int a, pos1, b, pos2; cin >> a >> pos1 >> b >> pos2;
            // checking badpos
            int badcount = 0;
            if(s1[pos1-1] != s2[pos1-1]) badcount++;
            if(s1[pos2-1] != s2[pos2-1]) badcount++;

            //swappping
            if(a == 1 && b == 1) 
            {
                swap(s1[pos1-1], s1[pos2-1]);
                if(s1[pos1-1] != s2[pos1-1]) badcount--;
                if(s1[pos2-1] != s2[pos2-1]) badcount--;
            }
            if(a == 1 && b == 2) 
            {
                swap(s1[pos1-1], s2[pos2-1]);
                if(s1[pos1-1] != s2[pos1-1]) badcount--;
                if(s1[pos2-1] != s2[pos2-1]) badcount--;
            }
            if(a == 2 && b == 1) 
            {
                swap(s2[pos1-1], s1[pos2-1]);
                if(s1[pos1-1] != s2[pos1-1]) badcount--;
                if(s1[pos2-1] != s2[pos2-1]) badcount--;
            }
            if(a == 2 && b == 2) 
            {
                swap(s2[pos1-1], s2[pos2-1]);
                if(s1[pos1-1] != s2[pos1-1]) badcount--;
                if(s1[pos2-1] != s2[pos2-1]) badcount--;
            }

            // decreasing the badpos
            badpos -= badcount;
            debug(badpos)
        }


    }
    
}

int32_t main()
{fast
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
freopen("error.txt", "w", stderr);
#endif

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}