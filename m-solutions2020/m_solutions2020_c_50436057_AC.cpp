/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/m-solutions2020/submissions/50436057
 * Submitted at: 2024-02-19 09:11:47
 * Problem URL: https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c
 * Result: AC
 * Execution Time: 191 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    for(ll i=k; i<n; i++) cout << (a[i-k] < a[i] ? "Yes" : "No") << endl;
    
    return 0;
}