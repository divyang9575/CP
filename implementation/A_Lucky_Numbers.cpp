#include<iostream>
using namespace std; 

const int N = 1e6 + 10;
int arr[N];

int maxi(int n){
    int m = 0;
    while(n>0){
        int dig = n%10;
        if(dig > m){
            m = dig;
        }
        n = n / 10;
    }
    return m;
}
int mini(int n){
    int m = 9;
    while(n>0){
        int dig = n%10;
        if(dig < m){
            m = dig;
        }
        n /= 10;
    }
    return m;
}

int main(){

    for(int i = 1 ; i<N; i++ )
    {
        arr[i] = maxi(i)- mini(i);
    }

    int t;
    cin >> t;
    while(t--){
        int l,r;
        cin >> l >> r;
        int mmax = 0;
        int ans = l;
        for(int i = l ; i <= r ; i++)
        {
            if(arr[i] >= mmax){
                mmax = arr[i];
                ans = i;
            }
            if(mmax == 9) break;  // very imp condition
        }
        
        cout << ans << endl; 
        }
}
        
            
    
