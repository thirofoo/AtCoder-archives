/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50628461
 * Submitted at: 2024-02-25 13:40:19
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_f
 * Result: WA
 * Execution Time: 510 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// S が data, F が lazy
using S = ld;
using F = ld;
// operator (作用素)
S op(S l,S r) {
    return l+r;
}
// 遅延データ反映
S mapping(F f,S x) {
    return f+x;
}
// 遅延データ作用 ※ g → f の順
F composition(F f,F g) {
    return f+g;
}
S e() { return 0; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n, l, d; cin >> n >> l >> d;
    ld dealer_burst = 0.0;
    lazy_segtree<S, op, e, F, mapping, composition, id> dealer(n+2), player(n+1);
    dealer.set(0, 1.0);
    rep(i,l) {
        ld np = dealer.get(i) / d;
        dealer.set(i, 0.0);
        dealer.apply(i+1, min(i+d+1, n+1), np);
        dealer_burst += max((i+d+1-(n+1)),0ll)*np;
    }

    ld ans = 0.0;
    for(ll i=n; i>=0; i--) {
        // 振らない場合の勝率
        ld cand = dealer.prod(0,i) + dealer_burst;

        // 振る場合の勝率
        cand = max(cand, player.prod(i+1,min(i+d+1,n+1)) / d);
        player.set(i, cand);
    }
    cout << player.get(0) << endl;
    
    return 0;
}