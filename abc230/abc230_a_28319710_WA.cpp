/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/28319710
 * Submitted at: 2022-01-04 15:12:21
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_a
 * Result: WA
 * Execution Time: 5 ms
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
    int n;cin >> n;
    if(n <= 41)cout << "AGC0" << n << endl;
    else cout << "AGC0" << n+1 << endl;
    return 0;
}