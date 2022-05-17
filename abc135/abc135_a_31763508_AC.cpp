/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc135/submissions/31763508
 * Submitted at: 2022-05-17 19:06:37
 * Problem URL: https://atcoder.jp/contests/abc135/tasks/abc135_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b; cin >> a >> b;
    if((a+b)%2 == 1)cout << "IMPOSSIBLE" << endl;
    else cout << (a+b)/2 << endl;
    return 0;
}