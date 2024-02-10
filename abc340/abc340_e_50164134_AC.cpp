/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50164134
 * Submitted at: 2024-02-10 21:37:59
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_e
 * Result: AC
 * Execution Time: 152 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// S が data, F が lazy
using S = ll;
using F = ll;
// operator (作用素)
S op(S l,S r) {
    return l + r;
}
// 遅延データ反映
S mapping(F f,S x) {
    return f + x;
}
// 遅延データ作用 ※ g → f の順
F composition(F f,F g) {
    return f + g;
}
S e() { return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
    rep(i,m) {
        ll now = seg.get(b[i]);
        ll T = now / n;
        ll rest = now % n;
        seg.set(b[i], 0);
        seg.apply(0, n, T);
        if( b[i]+rest+1 <= n ) seg.apply(b[i]+1, b[i]+rest+1, 1);
        else {
            seg.apply(b[i]+1, n, 1);
            seg.apply(0, (b[i]+rest+1)%n, 1);
        }
    }
    rep(i,n) cout << seg.get(i) << " ";
    cout << endl;
    
    return 0;
}