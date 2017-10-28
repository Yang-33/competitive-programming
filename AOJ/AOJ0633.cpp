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

/* -----  2017/10/29  Problem:  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0633  ----- */
/* ------問題------

ぬいぐるみの整理 (Plush Toys)
問題
ある JOI 関係者は，おもちゃ屋で働いている．今日は，店内にあるぬいぐるみコーナーの整理をすることになった．
ぬいぐるみコーナーの棚には，N 個のぬいぐるみが左から右に一列に並べられている．
棚は仕切りにより N 個の区画に区切られており，1 つの区画に 1 個のぬいぐるみを置く．
このおもちゃ屋は合計 M 種類のぬいぐるみを売っており，それぞれ 1 から M までの番号が付けられている．
棚に並べられた N 個のぬいぐるみは，それぞれこの M 種類のうちのいずれかである．また，それぞれの種類のぬいぐるみは，少なくとも 1 個は存在する．
見栄えを良くするため，同じ種類のぬいぐるみが全て連続して棚に置かれるように，ぬいぐるみを並べ替えたい．次のような方法で，ぬいぐるみを並べ替えることにした．
N 個のぬいぐるみのうちいくつかを選び，棚から取り出す．取り出さなかったぬいぐるみの位置は動かさない．
取り出したぬいぐるみを，好きな順に棚の空いている区画に戻していく．
並べ替えた後，同じ種類のぬいぐるみが全て連続して棚に置かれていなければならない． 並べ替えるために取り出すぬいぐるみの個数の最小値を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

bitDP[i]:=状態iまでぬいぐるみをつめたときの取り出したぬいぐるみの最小値
として回す。
かくぬいぐるみの累積和をもっておけばある区間に含まれる種類cのぬいぐるみの数がわかる。これを用いて状態iのぬいぐるみの数や、
次に入れるぬいぐるみの数がわかる。
これで解くことができる。

----解説ここまで---- */

ll N, M;

ll ans = 0LL;
int nu[1000010];
int kukan[22][1000010];
ll bitDP[1 << 21];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	FOR(i, 0, N) {
		cin >> nu[i];
		nu[i]--;
	}
	FOR(i, 0, N) {
		kukan[nu[i]+1][i+1]++;
	}
	//rui
	FOR(m, 1, M+1) {
		FOR(i, 1, N+1) {
			kukan[m][i+1] += kukan[m][i ];
			
		}
	}

	FOR(i, 0, 1 << M) {
		bitDP[i] = LINF;
	}

	bitDP[0] = 0;
	FOR(now, 0, (1 << M)) {
		//追加するやつ
		FOR(i, 1, M+1) {
			int pos = 0;
			if (((now >> (i-1)) & 1 )== 0) {
				FOR(j, 1, M+1) {
					if ((now >> (j-1)) & 1)pos += kukan[j][N];
				}
				ll num = kukan[i][N ] - (kukan[i][pos + kukan[i][N]] - kukan[i][pos]);
				bitDP[now | (1<<(i-1))] = min(bitDP[now |1<< (i-1)], bitDP[now] + num);
			}
		}

	}
	ans = bitDP[(1 << M) - 1];
	cout << ans << endl;

	return 0;
}
