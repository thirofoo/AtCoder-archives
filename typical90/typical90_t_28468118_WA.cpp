/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28468118
 * Submitted at: 2022-01-11 23:08:36
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_t
 * Result: WA
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll a,b,c; cin >> a >> b >> c;
    if(a < pow(c,b))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}