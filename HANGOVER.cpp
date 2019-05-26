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
    while(true) {
        float c;
        cin >> c;
        if(c==0) return 0;
        int n = 1;
        float sum = 0;
        while(sum < c) {
            ++n;
            sum += 1.0/n;
        }
        cout << n-1 << " card(s)" << endl;
    }
    return 0;
}
