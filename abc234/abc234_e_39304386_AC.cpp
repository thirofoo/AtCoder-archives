/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/39304386
 * Submitted at: 2023-02-28 11:59:00
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
 * Result: AC
 * Execution Time: 8 ms
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

unsigned long long digit_10(unsigned long long t){
    // ここでは0を1桁と見なす
    if(t == 0)return 1;
    ll dig = 0;
    while(t != 0){
        dig++;
        t /= 10;
    }
    return dig;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x; input(x);
    ll ans = LLONG_MAX;
    for(ll i=1;i<=9;i++){
        for(ll d=-9;d<=9;d++){
            // Xと同じ桁の等差数全列挙
            bool f = false;
            ll cand1 = 0;
            rep(j,digit_10(x)){
                cand1 *= 10;
                if(i+d*j < 0 || 9 < i+d*j){
                    f = true;
                    break;
                }
                cand1 += i+d*j;
            }
            if(!f && cand1 >= x){
                ans = min(ans,cand1);
            }
        }
    }
    print(ans);
    
    return 0;
}