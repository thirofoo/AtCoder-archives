/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc155/submissions/38460271
 * Submitted at: 2023-01-29 22:25:43
 * Problem URL: https://atcoder.jp/contests/arc155/tasks/arc155_a
 * Result: WA
 * Execution Time: 9 ms
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
    
    ll t; input(t);
    while(t--){
        ll n,k; string s; input(n,k,s);

        bool f = true;
        rep(i,n-1)f &= (s[i] == s[i+1]);
        if(f){
            print("Yes");
            continue;
        }

        ll tmp = k%n;
        f = true;
        ll left = 0,right = n-tmp-1;
        while(left < right){
            f &= (s[left] == s[right]);
            left++;
            right--;
        }
        left = tmp,right = n-1;
        while(left < right){
            f &= (s[left] == s[right]);
            left++;
            right--;
        }
        if(f)print(k%n == tmp ? "Yes" : "No");
        else{
            f = true;
            left = 0,right = n-1;
            while(left < right){
                f &= (s[left] == s[right]);
                left++;
                right--;
            }
            if(f)print(k%n == 0 ? "Yes" : "No");
            else print(k%(2*n) == n ? "Yes" : "No");
        }
    }
    
    return 0;
}