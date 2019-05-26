#include<bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define pb push_back
#define fr first
#define sc second

using namespace std;

const int inf = (int)1e9+5;
const int mod = (int)1e9+7;

bool isdiff(const vector<int> &v) {
    int n = v.size();
    if(n==0) return false;
    bool diff = false;
        forn(i,0,n) {
            if(v[i] != v[0]) diff = true;
        }
    return diff;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int s, c;
        cin >> s >> c;
        vector<int> v(s);
        forn(i,0,s) cin >> v[i];
        vector<vector<int> > dif;
        dif.pb(v);
        int counter = 0;
        while(isdiff(dif[counter])) {
            counter++;
            dif.pb(vector<int>());
            forn(i,1,dif[counter-1].size()) {
                dif[counter].pb(dif[counter-1][i]-dif[counter-1][i-1]);
            }
        }
        /*
        cout << "counter = " << counter << endl;
        forn(i,0,counter) {
            for(auto v : dif[i]) cout << v << ' ';
            cout << endl;
        }
        */
        int add[c];
        forn(i,0,c) add[i] = 0;
        while(counter >= 0) {
            forn(i,0,c) {
                add[i] += dif[counter].back();
                dif[counter].pb(add[i]);
            }
            counter--;
        }
        forn(i,s,s+c) cout << dif[0][i] << ' ';
        cout << endl;
    }
    return 0;
}
