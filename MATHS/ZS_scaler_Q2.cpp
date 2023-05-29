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

int minimumChunksRequired(long totalPackets, int uploadedChunks_rows, int uploadedChunks_columns, int *uploadedChunks[])
{
    long packetsRemaining = totalPackets - uploadedChunks_rows*1LL*uploadedChunks_columns;

    vector<long> packetSizes;
    int start = 1;
    int i = 0;
    while(start <= totalPackets)
    {
        long temp = uploadedChunks[i][0] - start;
        packetSizes.push_back(temp);

        start = uploadedChunks[i][1] + 1;
        i++;
        if(i > uploadedChunks_rows-1)
        {
            packetSizes.push_back(totalPackets+1 - start);
            start = totalPackets + 1;
        }
    }

    int cnt = 0;
    long ans = 0;
    for(int it = 0; it < packetSizes.size(); it++)
    {
        while(packetSizes[it] > 0)
        {
            int s = 0, e = packetSizes[it];
            while(s<=e)
            {
                int mid = e - (e-s)/2;
                if(pow(2,mid) <= packetSizes[it])
                {
                    ans = pow(2,mid);
                    s = mid + 1;
                }
                else e = mid - 1;
            }
            cnt++;
            packetSizes[it] -= ans;
            ans = 0;
        }
    }

    return cnt;
}

void solve()
{
    long noOfchunks; cin >> noOfchunks;
    int rows; cin >> rows;
    int m ; cin >> m; 

    int** chunks = new int*[rows];
    for (int i = 0; i < rows; ++i)
        chunks[i] = new int[m];

    fo(i,0,rows-1)
    {
        fo(j,0,m-1)
            cin >> chunks[i][j];
    }

    int ans = minimumChunksRequired(noOfchunks, rows, m, chunks);
    cout << ans << endl;

}

int32_t main()
{fast
    solve();
    return 0;
}