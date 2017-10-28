#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
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

/* -----  2017/10/28  Problem: ICPC2012国内予選B / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1180&lang=jp  ----- */
/* ------問題------

繰り返す10進数
数の10進表現は数字を並べ替えることで別の数になる． このことを使って数列を作ってみよう．

最初に，非負の整数a0と桁数Lを与える． 以下の規則を適用してaiからai+1を得る．

整数aiを，L桁の10進数で表記する． 必要であれば上位の桁に 0 を付け加える． たとえば 2012 という数は 6 桁の10進数で表記する場合は 002012 となる．
各桁の数字を並べ替えて，最も大きい整数と最も小さい整数を作る． 上の例では，最も大きい整数は 221000 であり， 最も小さい整数は 000122 = 122となる．
最も大きい整数から最も小さな整数を引いて，整数ai+1を得る． 上の例では 221000 − 122 を計算して 220878 を得る．
この計算を繰り返すと，数列 a0 , a1 , a2 , ... が得られる．

例えば 83268 という整数と桁数6が与えられた時，この計算を繰り返すと次のような数列 a0 , a1 , a2 , ... が得られる．

a0 = 083268
a1 = 886320 − 023688 = 862632
a2 = 866322 − 223668 = 642654
a3 = 665442 − 244566 = 420876
a4 = 876420 − 024678 = 851742
a5 = 875421 − 124578 = 750843
a6 = 875430 − 034578 = 840852
a7 = 885420 − 024588 = 860832
a8 = 886320 − 023688 = 862632
…
整数を表すための桁数が指定されているので， a0 , a1 , a2 , ... と順に計算していくといずれ同じ数が現れる．
すなわち，条件 ai = aj   を満たすような i  と j  (ただし i  > j  ) の組が必ず存在する． 上の例では，a8 = a1 = 862632 なので (i = 8, j = 1) の組が条件を満たす．

最初の整数 a0 と桁数 L  が与えられた場合に，条件 ai = aj (ただしi  > j  ) を満たす最小の i  を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

与えられた数を桁ごとに分解してソートすると、値が昇順になる。
このままstring-> int的なことをすれば最小の値が生成できる。
同様に後ろから値をとれば最大値がとれる。
この差が新しい値になるので、これをmapやpairのセットで保存しておく。
作った値が0とかでコーナーケースになるので、mapの判定がないときに0を返してしまうことから、map[A_0]=0からとするのではなく
カウントを１だけ増やして後から減らすと落ちなくなる。

(2017) map<string,int>でもてば一発だった

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		ll a, l;
		cin >> a >> l;
		if (a == 0 && l == 0)break;
		ll M = 0;
		ll m = 0;
		int cnt = 1;
		map<ll, ll>s;
		s[a] = 1;
		while (1) {
			M = 0; m = 0;
			char c[10];
			FORR(i, l - 1, -1) {
				c[i] = a % 10 + '0';
				a /= 10;
			}
			sort(c, c + l);
			FORR(i, l - 1, -1) {
				M += c[i] - '0';
				if (i != 0)
					M *= 10;
			}
			FOR(i, 0, l) {
				m += c[i] - '0';
				m *= 10;
			}
			while (m % 10 == 0 && m > 0) {
				m /= 10;
			}

//			cout << M << "  " << m << endl;
			ll nexta = M - m;
			//debug(nexta);

			cnt++;

			if (s[nexta] != 0) {
				ans = nexta;
				int jj = s[nexta];
				cout << jj-1 << " " << ans << " " << cnt - jj << endl;
				break;
			}
			else {
				a = nexta;
				s[nexta] = cnt;
			}

		}
	}

	return 0;
}
