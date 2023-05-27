/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41747999
 * Submitted at: 2023-05-27 21:31:17
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_d
 * Result: WA
 * Execution Time: 40 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,z; input(x,y,z);
    string s; input(s);
    vector<vector<ll>> dp(s.size()+1,vector<ll>(2,1e9));
    dp[0][0] = 0;
    rep(i,s.size()){
        if(s[i] == 'a'){
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+x);
            dp[i+1][0] = min(dp[i+1][0], dp[i][1]+z+x);
            dp[i+1][1] = min(dp[i+1][1], dp[i][1]+y);
        }
        else{
            dp[i+1][1] = min(dp[i+1][1], dp[i][1]+x);
            dp[i+1][1] = min(dp[i+1][1], dp[i][0]+z+x);
            dp[i+1][0] = min(dp[i+1][0], dp[i][0]+y);
        }
    }
    print( min(dp[s.size()][0],dp[s.size()][1]) );
    
    return 0;
}