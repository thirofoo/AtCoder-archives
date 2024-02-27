/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/50672975
 * Submitted at: 2024-02-27 12:09:34
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_e
 * Result: AC
 * Execution Time: 49 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC : 最大全域木問題に帰着
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    mint::set_mod(m);
    priority_queue<T> pq;
    rep(i,n) reps(j,i+1,n) pq.push(T((mint(a[i]).pow(a[j]) + mint(a[j]).pow(a[i])).val(), i, j));
    dsu uf(n);
    ll ans = 0;
    while( !pq.empty() ) {
        auto [c, u, v] = pq.top(); pq.pop();
        if( uf.same(u, v) ) continue;
        uf.merge(u, v);
        ans += c;
    }
    cout << ans << endl;
    
    return 0;
}
