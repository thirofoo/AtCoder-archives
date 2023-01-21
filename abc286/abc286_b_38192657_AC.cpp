/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc286/submissions/38192657
 * Submitted at: 2023-01-21 21:04:41
 * Problem URL: https://atcoder.jp/contests/abc286/tasks/abc286_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll n; string s; input(n,s);
    rep(i,n){
        if(i != n-1 && s[i] == 'n' && s[i+1] == 'a'){
            cout << "nya";
            i++;
        }
        else cout << s[i];
    }
    print();
    
    return 0;
}