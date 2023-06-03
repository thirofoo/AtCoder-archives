/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41970142
 * Submitted at: 2023-06-03 22:24:01
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_f
 * Result: WA
 * Execution Time: 61 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    sort(div.begin(),div.end());
    div.pop_back();
    return div;
}

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; input(n,s);
    vector<ll> shift; // 必ず入らなくちゃいけない日
    rep(i,s.size())if(s[i] == '.')shift.push_back(i);

    vector<mint> r(60);
    r[0] = 2;
    for(ll i=1;i<60;i++)r[i] = r[i-1]*r[i-1];

    vector<ll> div = divisor(n);
    reverse(div.begin(),div.end());
    set<ll> st;
    mint ans = 0;
    ll pre = -1;
    rep(i,div.size()){
        if(st.count(div[i]))continue;
        set<ll> mod;
        for(auto day:shift)mod.insert(day%div[i]);
        ll cand = div[i]-mod.size();
        mint add = 1;
        rep(j,20)if(cand & (1LL << j))add *= r[j];
        ans += add - 1;
        
        if(pre != -1){
            set<ll> mod2;
            ll tmp = euclid(div[i],pre);
            for(auto day:shift)mod2.insert(day%tmp);
            ll cand2 = tmp - mod2.size();
            add = 1;
            rep(j,20)if(cand2 & (1LL << j))add *= r[j];
            ans -= add - 1;
        }

        vector<ll> d = divisor(div[i]);
        for(auto ele:d)st.insert(ele);
        pre = div[i];
    }
    ans++;
    print(ans.val());
    
    return 0;
}