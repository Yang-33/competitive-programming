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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/10/28  Problem: Codechef snackdown2017 qual c SNAKEEAT　/ Link: https://www.codechef.com/SNCKQL17/problems/SNAKEEAT  ----- */
/* ------問題------

この問題はT個のケースからなる。

長さL_iのヘビさんがN匹いる。
ヘビは自身以外のヘビを共食いして、長さが1のびる。
ヘビは必ずしも共食いをしない。
シェフは長さK_i以上のヘビをできるだけ多く回収したい。
この質問がQ回ある。
うれしいヘビの増え方をしたときのシェフの回収できるヘビの数を各K_iごとに求めよ。

T≦5、N≦10^5、Q≦10^5、1≦K_i≦10^9、1≦L_i≦10^9

-----問題ここまで----- */
/* -----解説等-----

まず区間[x,y]を解に含める際に必要なコストを考える。
蛇の長さを昇順に並べ替え、与えられたkに対してどれだけ長さが足りないかを差をとって計算する。
ex: 5 8 9 10 21 ,k = 10 => -5 -2 -1 0 11
この累積和sumをとると、0 -5 -7 -8 -8 3 となる。(累積和のいつものずれ)
これによって、[x,y](1≦x≦y≦N)を採用するのに足りないコストは sum[y]-sum[x-1]となる。

この方法を採用すると毎回累積和を更新する必要があるために
Ｏ(TQN)の時間がかかってしまいTLEするが、少し考えると-kする作業はいつでもできることに気が付く。
よって二分探索の際に-k×(要素数)すれば足りないコストを求めることができる。=> sum[y]-k*y - sum[x-1]-k(x-1)

ある要素xよりも大きい区間を含んでもよいか、を二分探索してＯ(TQlogN)の計算量で求められる。
以下のコードでは先に含んでもよい区間を求め、それをnumとし、[x,num-1]を解に含んでもよいかをxについて二分探索をした。
探索区間は (l,r] で、r=numからはじめればよい。

----解説ここまで---- */

ll sumk[100010];//必要コスト
vector<int> L;
vector<ll> K;


void init() {
	FOR(i, 0, 100010) {
		sumk[i] = 0;
	}
	L.clear();
	K.clear();
}


/* [x,num-1]を解に含めてもいいか */
bool f(ll x, ll k,ll num) {
	
	ll costnum = sumk[num ] - k*(num);
	ll costmattan = sumk[x] - k*(x);
	return costnum - costmattan + x >= 0;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	
	int T; cin >> T;

	for (int _i = 1; _i <= T; _i++) {
		int N, Q; cin >> N >> Q;
		init();
		for (int j = 0; j < N; j++) {
			int _l; cin >> _l;
			L.push_back(_l);
		}
		sort(L.begin(), L.end());
		FOR(j, 1, N + 1) {
			sumk[j] += sumk[j - 1] + L[j - 1];
		}//sumk[j]:= L[j](1-index)を解に含ませる際に必要なコスト
		//sumk[x]-x*k-sumk[y-1]-(y-1)*k:= xからy(y<x)までを使うのに必要なコスト
		//FOR(i, 0, 1+N)cout << sumk[i] << " "; cout << endl;

		FOR(i, 0, Q) {
			ll k;
			ll ans = 0;
			cin >> k;
			int num = lower_bound(L.begin(), L.end(), k) - L.begin();
			ans += N - num;
			ll l = -1;
			ll r = num;
			//(l,r]
			FOR(j, 0, 100) {
				ll mid = (l + r) / 2;
				if (f(mid, k,num))r = mid;
				else l = mid;
			}
			ans += num - r;
			cout << ans << endl;

		}
		
	}

}