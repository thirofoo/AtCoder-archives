/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49975329
 * Submitted at: 2024-02-03 23:45:32
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_d
 * Result: RE
 * Execution Time: 2384 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

// 左上右下の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

inline bool outField(int x,int y,int h,int w){
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> s(n);
    vector<P> player;
    rep(i,n) {
        cin >> s[i];
        rep(j,n) if( s[i][j] == 'P' ) player.push_back(P(i,j));
    }
    queue<T> todo;
    todo.push(T(0,player[0].first, player[0].second, player[1].first, player[1].second));
    vector vis(n, vector(n, vector(n, vector(n, LLONG_MAX))));
    while(!todo.empty()) {
        auto &&[dis,x1,y1,x2,y2] = todo.front(); todo.pop();
        if( vis[x1][y1][x2][y2] <= dis ) continue;
        vis[x1][y1][x2][y2] = dis;
        rep(i,4) {
            ll nx1 = x1 + dx[i], ny1 = y1 + dy[i];
            ll nx2 = x2 + dx[i], ny2 = y2 + dy[i];
            if( outField(nx1,ny1,n,n) || s[nx1][ny1] == '#' ) nx1 = x1, ny1 = y1;
            if( outField(nx2,ny2,n,n) || s[nx2][ny2] == '#' ) nx2 = x2, ny2 = y2;
            if( vis[nx1][ny1][nx2][ny2] <= dis+1 ) continue;
            todo.push(T(dis+1,nx1,ny1,nx2,ny2));
        }
    }
    ll ans = LLONG_MAX;
    rep(i,n) rep(j,n) rep(k,n) rep(l,n) if( i == k && j == l ) ans = min(ans, vis[i][j][k][l]);
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
    
    return 0;
}