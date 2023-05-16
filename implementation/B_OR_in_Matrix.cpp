#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define endl '\n'
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
    int rows,cols; cin >> rows >> cols;

    int matB[rows][cols];

    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            cin >> matB[i][j];
        }
    }

    int matA[rows][cols];

    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            matA[i][j] = 1;
        }
    }

    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            if(matB[i][j] == 0)
            {
                fo(k,0,cols-1)
                {
                    matA[i][k] = 0;
                }
                fo(k,0,rows-1)
                {
                    matA[k][j] = 0;
                }
            }
        }
    }

    int tempMat[rows][cols];
    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            tempMat[i][j] = 0;
        }
    }

    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            if(matA[i][j] == 1)
            {
                fo(k,0,cols-1)
                {
                    tempMat[i][k] = 1;
                }
                fo(k,0,rows-1)
                {
                    tempMat[k][j] = 1;
                }
            }
        }
    }

    bool flag = true;
    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            if(matB[i][j] != tempMat[i][j])
            {
                flag = false; break;
            }
        }
    }

    if(flag == false){
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
    fo(i,0,rows-1)
    {
        fo(j,0,cols-1)
        {
            cout << matA[i][j] << " ";
        }
        cout << endl;
    }
    
}

int main()
{fast
    solve();
    return 0;
}