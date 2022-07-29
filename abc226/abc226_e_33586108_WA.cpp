/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/33586108
 * Submitted at: 2022-07-29 15:23:29
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_e
 * Result: WA
 * Execution Time: 106 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    vector<vector<int>> Graph(n);
    vector<int> deg(n,0);
    vector<P> edge;
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        deg[a]++; deg[b]++;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        edge.push_back(P(a,b));
    }

    //連結成分ごとに分けるpart
    vector<int> visited(n,-1);
    vector<vector<int>> comp;
    int cnt = 0;
    queue<int> todo;
    rep(i,n){
        if(visited[i] >= 0)continue;
        vector<int> tmp;
        todo.push(i);
        while(!todo.empty()){
            int now = todo.front(); todo.pop();
            if(visited[now] >= 0)continue;
            visited[now] = cnt;
            tmp.push_back(now);
            for(auto k:Graph[now])todo.push(k);
        }
        comp.push_back(tmp);
        cnt++;
    }

    //各連結成分において何個の辺が存在するかcountするpart
    mint ans = 0;
    for(auto k:comp){
        int tmp = 0;
        for(auto l:k)tmp += deg[l];
        if(tmp == 2*k.size()){
            if(ans != 0)ans *= 2;
            else ans = 2;
        }
    }
    cout << (ans.val() == 1 ? 0 : ans.val()) << endl;
    
    return 0;
}