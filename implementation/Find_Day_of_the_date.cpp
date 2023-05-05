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

string dayOfTheWeek(int day, int month, int year) 
{
    // Write your code here.
    string sevenDays[] = {"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

    int daysTillMonth[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    
    int daysPassed = (year - 1) * 365 + daysTillMonth[month - 1] + day;

    if(month <= 2)
    {
        year--;
    }
    int leapDaysPass = (year/4)-(year/100)+(year/400);

    daysPassed += leapDaysPass;

    return sevenDays[daysPassed%7];
}

int main()
{fast
    int t;
    cin >> t;
    while(t--){
        int year, month, day;
        cin >> day >> month >> year;
        cout << dayOfTheWeek(day,month,year) << endl;
    }
    return 0;
}