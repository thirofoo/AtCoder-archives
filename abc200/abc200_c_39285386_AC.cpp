/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/39285386
 * Submitted at: 2023-02-27 14:37:02
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_c
 * Result: AC
 * Execution Time: 38 ms
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
    vector<ll> a(n);
    vector<ll> rest(200,0);
    rep(i,n){
        input(a[i]);
        rest[a[i]%200]++;
    }
    ll ans = 0;
    rep(i,200)ans += rest[i]*(rest[i]-1)/2;
    print(ans);
    
    return 0;
}