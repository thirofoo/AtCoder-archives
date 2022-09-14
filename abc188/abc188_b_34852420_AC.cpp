/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc188/submissions/34852420
 * Submitted at: 2022-09-14 18:11:22
 * Problem URL: https://atcoder.jp/contests/abc188/tasks/abc188_b
 * Result: AC
 * Execution Time: 28 ms
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
    
    ll n; input(n);
    vector<ll> a(n),b(n);
    rep(i,n)input(a[i]);
    rep(i,n)input(b[i]);
    ll ans = 0;
    rep(i,n){
        ans += a[i]*b[i];
    }
    if(ans == 0)print("Yes");
    else print("No");
    
    return 0;
}