#include<bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define pb push_back
#define fr first
#define sc second

using namespace std;

const int inf = (int)1e9+5;
const int mod = (int)1e9+7;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    forn(i,0,n) cin >> a[i];
    sort(a,a+n);
    int ans= 0;
    forn(i,0,n) ans += upper_bound(a+i+1,a+n,a[i]+k) - lower_bound(a+i+1,a+n,a[i]+k);
    cout << ans;
    return 0;
}
