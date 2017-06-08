#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/05/01  Problem: JOI予選 2012 3  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0578  ----- */
/* ------問題------

ある看板s(i)について、削除して残った文字列の間隔が一致しており、それがSである場合にこれは作成可能な看板として扱われる。
このような看板はなんまいあるか。

-----問題ここまで----- */
/* -----解説等-----

削除する文字の間隔、位置について全探索すればよい。
めんどくさかったgotoつかわなくてもOKであるということが分かっていればans++とすればいいことにも後で気が付いた。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N;
	ll ans = 0;
	string S;
	int slen = (int)S.size();

	cin >> N >> S;
	FOR(i,0,N){
		string s; cin >> s;
		int len = s.length();
		FOR(j, 1,len){
			FOR(k,0,len){
				int cnt = 0;
				int idx = 0;
				int now;
				for (now = k; now < len; now += j) {
					if (s[now] == S[idx]) {
						idx++;
						cnt++;
					}
					else {
						idx = cnt = 0;
						break;
					}

					if (cnt == S.length()) {
						ans++;
						goto kim;
					}
				}
			}
		}
	kim:;
	}

	cout << ans << endl;

	return 0;
}
