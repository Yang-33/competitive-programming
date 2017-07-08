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

/* -----  2017/07/07  Problem: ukuku09_contest B  / Link: https://hoj.hamako-ths.ed.jp/onlinejudge/problems/767  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

動的BIT or seg木。
BITの int data[] を map<int,int>data みたいにすればちょっと重くなるけど
メモリを使う部分しか消費しないのでうれしい。

何人参加していないかという情報をノードに持たせて、ある人が参加していることが分かった時刻にいもす法っぽく情報を修正すればいい。
C日目以降の出席人数が知りたいので、出席日が更新されるごとに、０日目の情報からその日の情報に情報を修正していき、
[0,C)の範囲にいるC日目以降に出席していない人数を求めればよい。

または平衡二分木(むり)

----解説ここまで---- */

ll N, Q;


ll ans = 0LL;

struct BIT { // 0-index
	ll N;
	map<ll, int> data;
	BIT(ll n) {
		N = n;
	}
	void add(ll i, int w) { // a[i] += w
		i++;
		for (ll x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	int sum(ll i) {
		int ret = 0;
		i++;
		for (ll x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
};

ll last[100005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	BIT bit(INT_MAX);
	bit.add(0, N);
	FOR(i, 0, Q) {
		int num; cin >> num;
		if (num == 1) {
			int a, b; cin >> a >> b;
			b--;
			if (last[b] < a) {
				bit.add(last[b], -1);
				last[b] = a;
				bit.add(last[b], 1);
			}
		}
		else if (num == 2) {
			int c; cin >> c;
			ans = N - bit.sum(c - 1);
			cout << ans << endl << flush;

		}
	}

	return 0;
}
