#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/28  Problem: codeforces Educatinal18 D / Link: http://codeforces.com/contest/792/problem/D  ----- */
/* ------問題------

図のような完全２分木があり、各頂点には番号が振られている。現在位置が与えられ、移動の指示があるので
これが実現可能なら移動し、実現不可能なら移動しないを繰り返し、最終地点を各クエリごとにこたえよ。

-----問題ここまで----- */
/* -----解説等-----

与えられた完全２分木の深さと現在地の深さと左右どこにいるのかがわかればあとはクエリに従って移動していけばよい。
移動する際には左右どちらから来たかを記録することで値の遷移を実現する実装をした。

----解説ここまで---- */

ll N,Q;

ll ans = 0LL;

ll func(ll a, string s, ll bb) {
    //cout << __LINE__ << endl;
    ll num = a;
    int dpt = 0;
    ll x = (bb + 1) / 2;
    ll y = x;
    char ss[1000];
    while (num != x) {
        if (x > num) {
            dpt++;
            x -= y / 2;
            y /= 2;
            ss[dpt] = 'L';
        }
        else {
            dpt++;
            x += y / 2;
            y /= 2;
            ss[dpt] = 'R';//child R
        }
    }
    ll n = 1;
    int mdpt = 0;
    while ((bb+1)/2!=n)
    {
        n *= 2;
        mdpt++;
    }
    FOR(i, 0, s.size()) {

        if (s[i] == 'U') {
            if (dpt==0)continue;
            else {
                if (ss[dpt] == 'L') {
                    num += pow(2, mdpt - dpt);
                    dpt--;
                    ss[dpt+1] = '\0';
                }
                else if (ss[dpt] == 'R') {
                    num -= pow(2, mdpt - dpt);
                    dpt--;
                    ss[dpt+1] = '\0';

                }
            }
        }
        else if (s[i] == 'L') {
            if (dpt == mdpt)continue;
            num -= pow(2, mdpt - dpt - 1);
            dpt++;
            ss[dpt] = 'L';
        }
        else if (s[i] == 'R') {
            if (dpt == mdpt)continue;
            num += pow(2, mdpt - dpt - 1);
            dpt++;
            ss[dpt]= 'R';
        }
    }

   
    return num;
}


int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N>>Q;
  FOR(i, 0, Q) {
      ll st; string S;
      cin >> st >> S;
      cout << func(st, S, N) <<  endl;
  }

  return 0;
}
