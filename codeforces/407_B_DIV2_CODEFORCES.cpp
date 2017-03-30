#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
/* -----  2017/03/30  Problem: CodeForces407 B div2 / Link: http://codeforces.com/contest/789/problem/B ----- */
/* ------問題------

数列 b_i+1=b_i * qを考える。
数q,b1と、数列anとlが与えられるので、|bi|≦lの範囲で取りうるiからなるbiのうち、a_k とは異なるものの個数を求めよ。
もし無限に書き出せる際にはinfと出力せよ。

-----問題ここまで----- */
/* -----解説等-----

q=0,q=1,q=1,b1=0, |b1|>lのときに場合分けをし、それ以外は指数関数的に数が増大するので新しい値をつくり、
それがanにないかどうかをlogぐらいで判定すればよい。
set or unordered_setで通る。
本番では通らずつらい思いをしたが問題をよく読みましょう。

----解説ここまで---- */

ll N;
unordered_set<ll> ss;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    vector<ll> a;
    FOR(i, 0, m) {
        ll s; cin >> s;
        a.push_back(s);
        ss.insert(s);
    }
    sort(a.begin(), a.end());
    if (b == 0) {// 0
        FOR(i, 0, m) {
            if (a[i] == b) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << "inf" << endl;
        return 0;
    }
    if (abs(b) > l) {
        cout << 0 << endl;
        return 0;
    }

    if (q == 0) {
        if (abs(b) > l) {
            FOR(i, 0, m) {
                if (a[i] == 0) {
                    cout << 0 << endl; return 0;
                }
            }
            cout << "inf" << endl; return 0;
        }

        bool f = false;//0*
        bool f2 = false;//b
        FOR(i, 0, m) {
            if (a[i] == 0) {
                f = true;
            }
            if (b == a[i]) f2 = true;
        }
        if ((f&&f2)||(f&&(b==0)))cout << 0 << endl;
        else if (f) cout << 1 << endl;
        else cout << "inf" << endl;

            return 0;
    }
    if (q == 1 ) {
        if (abs(b) <= l) { //bのみ
            bool flag = false;
            FOR(i, 0, m) {
                if (b == a[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << 0 << endl; return 0;
            }
            else {
                cout << "inf" << endl; return 0;
            }
        }
        else cout << 0 << endl;
            return 0;
    }
    if (q == -1) {
        if (abs(b) <= l) { // b, -b*
            bool f = false, f2 = false;
            FOR(i, 0, m) {
                if (a[i] == b)f2 = true;
                if (a[i] == (-1)*b)f = true;
            }
            if (f&&f2)cout << 0 << endl;
            else cout << "inf" << endl;
            return 0;
        }
        else cout << 0 << endl; return 0;
    }
    else {
        ll nb = b;
        while (abs(nb) <= l) {
            //ll k = upper_bound(a.begin(), a.end(), nb) - lower_bound(a.begin(), a.end(), nb);
            ll k = ss.count(nb);
            if (k == 0)ans++;
            nb = nb*q;
        }
        if (ans >= 1e6)cout << "inf" << endl;
        else cout << ans << endl;
    }
    return 0;
}