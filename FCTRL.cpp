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
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = 0;
        for(ll i = 5; n >= i; i*=5) {
            ans += n/i;
        }
        cout << ans << endl;
    }
    return 0;
}
