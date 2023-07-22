/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc182/submissions/43819203
 * Submitted at: 2023-07-22 15:47:10
 * Problem URL: https://atcoder.jp/contests/abc182/tasks/abc182_d
 * Result: AC
 * Execution Time: 35 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n+1,0);
    ll ans = 0, now = 0, max_d = 0;
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
        max_d = max(max_d, a[i+1]);
        ans = max(ans, now + max_d);
        now += a[i+1];
    }
    cout << ans << endl;
    
    return 0;
}