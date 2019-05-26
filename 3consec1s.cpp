#include<bits/stdc++.h>

#define forn(i,a,b) for(int i = a; i < b; ++i)
#define ll long long
#define pb push_back
#define fr first
#define sc second

using namespace std;

const int inf = (int)1e9+5;
const int mod = (int)1e9+7;
int n;

int solve(int i, int b, int dp[][4], string &s) {
    if(i<0) {
            return b==3;
    }
    if(dp[i][b]!=-1) {
            return dp[i][b];
    }
    s[i] = '0';
    dp[i][b] = solve(i-1,0,dp,s);
    s[i] = '1';
    dp[i][b] += solve(i-1,b+1,dp,s);
    s[i]='0';
    return dp[i][b];
}

bool check(string &s) {
    int n = s.length();
    for(int i = 2; i < n; i++) {
        if(s[i]=='1' && s[i-1]=='1' && s[i-2]=='1') return 1;
    }
    return 0;
}

int brute(int i, string &s) {
    if(i<0) {
        if(check(s)) return 1;
        return 0;
    }
    s[i]='0';
    int ans = brute(i-1,s);
    s[i]='1';
    ans += brute(i-1,s);
    s[i]='0';
    return ans;
}

int main()
{
    cin >> n;
    string s1(n,'0'), s2(n,'0');
    int dp[n][4];
    forn(i,0,n) forn(j,0,4) dp[i][j]=-1;
    forn(i,0,n) {
        dp[i][3] = (1<<(i+1));
    }
    cout << solve(n-1,0,dp,s1) ;//<< " " << brute(n-1,s2);
    return 0;
}
