/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc008/submissions/41305064
 * Submitted at: 2023-05-11 19:09:11
 * Problem URL: https://atcoder.jp/contests/agc008/tasks/agc008_a
 * Result: WA
 * Execution Time: 8 ms
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
    
    ll x,y; input(x,y);
    if(x > 0 && y > 0)print(y-x);
    else if(x > 0 || y > 0)print(abs(y)-abs(x)+1);
    else print(abs(y)-abs(x)+2);
    
    return 0;
}