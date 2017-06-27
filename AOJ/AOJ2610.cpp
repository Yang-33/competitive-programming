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

/* -----  2017/06/22  Problem: AOJ 2610  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2610&lang=jp ----- */
/* ------問題------

イクタ君は速いプログラムが大好きである。最近は、除算のプログラムを高速にしようとしている。しかしなかなか速くならないので、「常識的に考えて典型的」な入力に対してのみ高速にすればよいと考えた。イクタ君が解こうとしている問題は次のようなものである。

与えられた非負整数nに対し、10進法でp(n)−1桁の正整数11...1をp(n)で割ったあまりを求めよ。ただしp(n)は22...2（2がn個）より大きい最小の素数を表すとする。p(0)=2とする。

あなたの仕事は、イクタ君より速くプログラムを完成させることである。

-----問題ここまで----- */
/* -----解説等-----

p(n)-1桁の111111...1111 mod p(n)について、
これは(10^(p(n)-1)-1)/9 mod (p(n)) と表すことができる。
フェルマーの小定理から
これについて分子が0になるので答えは0であるが、
N=0,1,2のとき、p(N)はそれぞれ、2,3,5となり分子の10か分母の9と互いに素ではないので
これらが例外なケースとなる。

----解説ここまで---- */

ll N;

ll ans = 0LL;

//10^()

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N == 0)cout<<1<<endl;
	else if (N ==1 )cout << 2 << endl;
	else if (N == 2)cout << 1<< endl;
	else cout << 0 << endl;

	return 0;
}
