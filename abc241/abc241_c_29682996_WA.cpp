/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/29682996
 * Submitted at: 2022-02-26 21:30:13
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_c
 * Result: WA
 * Execution Time: 41 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<string> field(n);
    rep(i,n)cin >> field[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-6;j++){
            int b = 0,w = 0;
            rep(k,6){
                if(field[i][j+k] == '#')b++;
                else w++;
            }
            if(b >= 4)return cout << "Yes" << endl,0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=n-6;j++){
            int b = 0,w = 0;
            rep(k,6){
                if(field[j+k][i] == '#')b++;
                else w++;
            }
            if(b >= 4)return cout << "Yes" << endl,0;
        }
    }
    for(int i=0;i<=n-6;i++){
        int b = 0,w = 0;
        rep(k,6){
            if(field[i+k][i+k] == '#')b++;
            else w++;
        }
        if(b >= 4)return cout << "Yes" << endl,0;
    }
    for(int i=0;i<=n-6;i++){
        int b = 0,w = 0;
        rep(k,6){
            if(field[i+k][n-1-i-k] == '#')b++;
            else w++;
        }
        if(b >= 4)return cout << "Yes" << endl,0;
    }
    cout << "No" << endl;
    return 0;
}