#include<bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define pb push_back
#define fr first
#define sc second

using namespace std;

const int inf = (int)1e9+5;
const int mod = (int)1e9+7;

string s1(int n)
{
    int t=1;
    //cin >> t;
    while(t--) {
        string k, k1;
        //cin >> k;
        k = to_string(n);
        int l = 0;
        while(l < k.length()-1 && k[l] == '0') l++;
        k = k.substr(l);
        k1=k;
        int len = k.length();
        int i = len/2 - (len%2==0);
        bool palin = true, noteq = false;
        forn(j,i+1,len) {
            if(k[j] <= k[len-j-1]) {
                    if(k[j] != k[len-j-1]) noteq = true;
                    k[j] = k[len-j-1];
            }
            else if(!noteq) {
                    palin = false;
                    break;
            }
            else {
                k[j] = k[len-j-1];
            }
        }
        if(noteq && palin) {
            //cout << k << endl;
            return k;
            continue;
        }
        while(i>=0) {
            if(k[i] != '9') {
                k[i]++;
                break;
            }
            else k[i] = '0';
            i--;
        }
        string ans = k;
        if(i<0) {
                ans[0] = '1';
                len++;
                ans.push_back('1');
                forn(i,1,len-1) {
                    ans[i] = ans[len-i-1] = '0';
                }
        }
        else {
            forn(i,0,len)
            ans[len-i-1] = ans[i];
        }
       // cout << ans << endl;
       return ans;
    }

}

bool ispalin(int k){
    string s = to_string(k);
    forn(i,0,s.length()){
        if(s[i]!=s[s.length()-i-1]) return 0;
    }
    return 1;
}

string s2(int k){
    forn(i,k+1,1000001){
        if(ispalin(i)) return to_string(i);
    }
    return "0";
}

int main(){
    forn(i,0,1000001){
        if(s1(i)!=s2(i)) {
            cout << "i=" << i << endl;
            cout << s1(i) << " " << s2(i) << endl;
            return 0;
        }
    }
}
