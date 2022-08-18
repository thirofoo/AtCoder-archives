/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc049/submissions/34118191
 * Submitted at: 2022-08-18 11:02:01
 * Problem URL: https://atcoder.jp/contests/agc049/tasks/agc049_b
 * Result: WA
 * Execution Time: 18 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,c1 = 0,c2 = 0; string s,t; cin >> n >> s >> t;
    rep(i,n)if(s[i] == '1')c1++;
    rep(i,n)if(t[i] == '1')c2++;
    if(c1 < c2 || c1%2 != c2%2)return cout << -1 << endl,0;

    ll l = 0,r = 0,cnt1 = 0,cnt2 = 0,ans = 0;
    while(l != n & r != n){
        if(t[l] == '0')l++;
        else{
            if(s[r] == '0')r++;
            else{
                if(cnt1%2 == 1){
                    cnt1++; ans += r; r++; 
                }
                else if(l > r){
                    cnt1++; ans -= r; r++;
                }
                else{
                    ans += r-l;
                    l++; r++; cnt2++;
                }
            }
        }
    }
    cout << (cnt2 == c2 ? ans : -1) << endl;
    
    return 0;
}