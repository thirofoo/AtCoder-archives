/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/50917423
 * Submitted at: 2024-03-05 14:08:34
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_d
 * Result: WA
 * Execution Time: 37 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, d; cin >> n >> d;
    vector<P> wall;
    rep(i,n) {
        ll l, r; cin >> l >> r;
        wall.emplace_back(l, r);
    }
    sort(wall.begin(), wall.end(), [](P &a, P &b) {
        return a.second < b.second;
    });
    ll ans = 0, break_left = 0;
    rep(i,n) {
        auto [l, r] = wall[i];
        if( l <= break_left && break_left <= r ) continue;
        break_left = r + d-1;
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}