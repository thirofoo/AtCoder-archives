/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc237/submissions/30120494
 * Submitted at: 2022-03-14 14:21:33
 * Problem URL: https://atcoder.jp/contests/abc237/tasks/abc237_e
 * Result: WA
 * Execution Time: 2236 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    vector<int> height(n);
    rep(i,n)cin >> height[i];
    vector<vector<int>> Graph(n);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    vector<int> unenjoy(n,INT_MAX);
    priority_queue<P,vector<P>,greater<P>> todo;
    unenjoy[0] = 0;
    for(auto k:Graph[0]){
        todo.push(P(0,k));
    }
    while(!todo.empty()){
        auto [from,to] = todo.top(); todo.pop();
        if(height[from] >= height[to]){
            if(unenjoy[to] > unenjoy[from]){
                unenjoy[to] = unenjoy[from];
                for(auto k:Graph[to]){
                    todo.push(P(to,k));
                }
            }
        }
        else{
            if(unenjoy[to] > unenjoy[from] + height[to]-height[from]){
                unenjoy[to] = unenjoy[from] + height[to]-height[from];
                for(auto k:Graph[to]){
                    todo.push(P(to,k));
                }
            }
        }
    }
    int ans = 0;
    rep(i,n)ans = max(ans,height[0]-height[i]-unenjoy[i]);
    cout << ans << endl;
    return 0;
}