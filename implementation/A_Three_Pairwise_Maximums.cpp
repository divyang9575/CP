#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        
        int a,b,c;
        bool flag = false;
        
        if(x == y && x == z)
        {
            a=x;
            b=x;
            c=x;
            flag = true;
        }
        else if((x==y && x!=z))
        {
            if(x < z){
               flag = false;
            }
                
            else {
                flag = true;
                a=x;
                b=z;
                c=z;
            }
        }
        else if((x==z && x!=y))
        {
            
            if(x < y){
               flag = false;
            }
                
            else {
                flag = true;
                a=x;
                b=y;
                c=y;
            }
        }
        else if(y==z && y!=x)
        {
            if(y<x){
                 flag = false;
            }
            else
            {
                flag = true;
                a=y;
                b=x;
                c=x;
            }
        }
        else flag = false;
        
        if(flag)
        {
            cout << "YES\n";
            cout << a <<" "<< b <<" " << c<<" " << endl;
        } 
        else cout << "NO\n";
    }
}