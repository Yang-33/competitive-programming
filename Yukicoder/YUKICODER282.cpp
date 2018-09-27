#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/26  Problem: yukicoder 282  / Link: http://yukicoder.me/problems/no/282  ----- */
/* ------問題------

授業中にもかかわらず遊んでしまうdaveは、
理科の実験中に、色んな重さの種類があるおもりをすべて使って、
ちょうど天秤が水平になるおもりの組み合わせがあるかを知りたくなったようで、それに遊び呆けてる。
水平になるおもりの組み合わせがあるかどうかは分かったものの、おもりの重さが分からなくなってしまいおもりと天秤を片付けられなくなったdaveは途方に暮れている。
あなたはdaveのためにおもりを重さの昇順に並べてあげて、授業に集中させるようにしてください。


N個の重さが互いに異なるおもりとN個の天秤があります。
おもりと天秤にはそれぞれ1からNの番号がふられています。
おもりの重さは0より大きいことが保証されています。
あなたは２つのおもりの重さを天秤で調べることができます。
天秤を使っておもりの関係を調べて、おもりを重さの昇順に並べましょう。

ただし、天秤の操作は2000回までしかできないものとする。(2015/09/19 10:40追記)

-----問題ここまで----- */
/* -----解説等-----

上:バイトニックソート
下:奇偶転置ソート

----解説ここまで---- */

void solve2(vector<PII>&q, VI&a, int N) {
	VI out(2 * N, 0);
	int f = 0;
	FOR(i, 0, N) {
		if (i == SZ(q))break;
		int x, y; tie(x, y) = q[i];
		if (a[x] != INF && a[y] != INF) {
			out[2 * i] = a[x];
			out[2 * i + 1] = a[y];
			f = 1;
		}
	}
	if (!f)return;

	cout << "?";
	FOR(i, 0, SZ(out)) {
		cout << " " << out[i];
	}cout << endl;

	FOR(i, 0, N) {
		char c; cin >> c;
		if (c == '>') {
			int x, y; tie(x, y) = q[i];
			if (a[x] != INF && a[y] != INF) {
				swap(a[x], a[y]);
			}
		}
	}
	q.clear();
}

void f(VI &a, int N, int exp) {
	FOR(i, 0, exp) {
		vector<PII> q;
		{
			int s = 1 << i;
			int t = 1 << (exp - 1 - i);
			FOR(k, 0, t) {
				FOR(p, 0, s) {
					q.push_back(PII(p + 2 * s*k, 2 * s - 1 - p + 2 * s*k));
				}
			}
		}
		solve2(q, a, N);
		{
			FORR(j, i - 1, 0 - 1) {
				int s = 1 << j;
				int t = 1 << (exp - 1 - j);
				FOR(k, 0, t) {
					FOR(p, 0, s) {
						q.push_back(PII(p + 2 * s*k, p + s + 2 * s*k));
					}
				}
				solve2(q, a, N);
			}
		}
	}
}

void solve(int N) {
	int exp = 1;
	while (N > (1 << exp)) {
		exp++;
	}
	VI a(1 << exp, INF);
	FOR(i, 0, N) {
		a[i] = i + 1;
	}
	f(a, N, exp);

	cout << "!";
	FOR(i, 0, N) {
		cout << " " << a[i];
	}
	cout << endl;
	exit(0);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	solve(N);
	auto ask = [&N](VI &a, int firststate) {
		cout << "?";
		int cnt = 0;
		for (int i = firststate & 1; i + 1 < N; i += 2) {
			cnt++;
			cout << " " << a[i] << " " << a[i + 1];
		}
		FOR(i, cnt, N) {
			cout << " 0 0";
		}

		cout << endl;

		vector<char> res(N);
		FOR(i, 0, N) {
			cin >> res[i];
		}
		return res;
	};

	VI a(N);
	iota(ALL(a), 1);
	FOR(st, 0, 2 * N) {
		vector<char>res = ask(a, st);
		FOR(i, 0, SZ(res)) {
			if (res[i] == '>') {
				swap(a[st % 2 + 2 * i], a[st % 2 + 2 * i + 1]);
			}
		}
	}

	cout << "!";
	FOR(i, 0, N) {
		cout << " " << a[i];
	}
	cout << endl;

	return 0;
}
