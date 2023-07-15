/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc095/submissions/43574156
 * Submitted at: 2023-07-15 15:45:51
 * Problem URL: https://atcoder.jp/contests/abc095/tasks/abc095_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    string s; input(s);
    ll ans = 700;
    rep(i,3)if( s[i] == 'o' )ans += 100;
    print(ans);
    
    return 0;
}