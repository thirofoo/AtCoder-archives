/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc307/submissions/42896807
 * Submitted at: 2023-06-24 21:05:42
 * Problem URL: https://atcoder.jp/contests/abc307/tasks/abc307_b
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<string> s(n);
    rep(i,n)input(s[i]);
    rep(i,n){
        string now = "";
        rep(j,n){
            if(i == j)continue;
            now = s[i] + s[j];
            ll idx = 0;
            bool f = true;
            while(idx <= now.size()-idx-1){
                f &= (now[idx] == now[now.size()-idx-1]);
                idx++;
            }
            if(f){
                print("Yes");
                return 0;
            }
        }
    }
    print("No");
    
    return 0;
}