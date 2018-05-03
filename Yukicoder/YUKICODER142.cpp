#include <bits/stdc++.h>
using namespace std;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl

/* -----  2018/05/03  Problem: yukicoder 142  / Link: http://yukicoder.me/problems/no/142  ----- */
/* ------問題------

次の操作を行った後，最終的な配列 A=A1,A2,…,AN を求めてください．
ただし，配列 A の各要素は大きくなる可能性があるため，各要素が偶数か奇数かのみを出力してください．
ここで，配列 A の連続する部分列を A[i,j]=Ai,Ai+1,…,Aj と書き表します．
例えば，B=A[i,i+10] と書いた時，B3=Ai+2 です．
最初に，配列 A の要素の数 N，乱数の種 S と，乱数生成のパラメータ X,Y,Z が与えられるので，次の方法で配列 A を作成します：
A1=S，
Ak+1=(X×Ak+Y) mod Z,k=1,2,…,N−1．
次に Q 個の処理が与えられます．
各処理は，4 つの正整数 S,T,U,V の組で，次のような操作を行います．
配列 A の S 番目の要素から，T 番目の要素までをコピーし，B=A[S,T] とします．
そして，A[U,V] の各要素に B の各要素を足し込みます．つまり，
Ak←Ak+Bk−U+1,U≤k≤V
と代入操作を行います．
この Q 個の操作が全て終わった後，配列 A の各要素に対して，偶数であれば E，奇数であれば O と置き換えてできる長さ N の文字列を出力するプログラムを書いてください．

-----問題ここまで----- */
/* -----解説等-----

厳しい

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	using VL = vector<unsigned long long >;
	using LL = unsigned long long;

	long long N, S, X, Y, Z;
	cin >> N >> S >> X >> Y >> Z;
	vector<long long> a(N);
	a[0] = S;
	FOR(i, 1, N) {
		a[i] = (X*a[i - 1] + Y) % Z;
	}
	const int W = 64;
	VL bit((N + W - 1) / W + 1, 0);
	FOR(i, 0, N) {
		if (a[i] % 2)bit[i / W] |= (1LL << (i%W));
	}

	int Q; cin >> Q;
	VL tmp((N + W - 1) / W, 0);
	FOR(q, 0, Q) {
		int s, t, u, v; cin >> s >> t >> u >> v;
		s--, u--;

		// [s,t)を先頭にもってきて[u,v)に加算

		int len = t - s;
		{
			int i = 0, j = s;
			if (j%W == 0) {
				for (; i + W <= len; i += W, j += W) {
					tmp[i / W] = bit[j / W];
				}
			}
			else {
				int ss = j%W, tt = W - ss;
				LL cur = bit[j / W], nx;
				for (; i + W <= len; i += W, j += W) {
					nx = bit[j / W + 1];
					tmp[i / W] = (cur >> ss) | (nx << tt);
					cur = nx;
				}
			}
			tmp[i / W] = 0;
			for (; i < len; i++, j++) {
				tmp[i / W] |= (bit[j / W] >> (j%W) & 1) << (i%W);
			}
		}
		{
			int i = 0, j = u;
			if (j % W == 0) {
				for (; i + W <= len; i += W, j += W) {
					bit[j / W] ^= tmp[i / W];
				}
			}
			else {
				int ss = j % W, tt = W - ss;
				LL p;
				for (; i + W <= len; i += W, j += W) {
					p = tmp[i / W];
					bit[j / W] ^= p << ss;
					bit[j / W + 1] ^= p >> tt;
				}
			}
			for (; i < len; ++i, ++j)
				bit[j / W] ^= (tmp[i / W] >> (i % W) & 1) << (j % W);
		}
	}


	FOR(i, 0, N) {
		bool x = bit[i / W] & (1LL << (i%W));
		cout << "EO"[x];
	}cout << endl;

	return 0;
}
