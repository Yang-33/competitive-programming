#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/10/02  Problem: Nagoya_univ_contest16_e  / Link: http://agc010.contest.atcoder.jp/tasks/agc010_b  ----- */
/* ------問題------

N 個の箱が円環状に並んでおり、i 番目の箱には Ai 個の石が入っています。

以下の操作を繰り返して、全ての石を取り除くことができるか判定してください。

箱を一か所選ぶ。それを i 番目としたとき、1 から N の各 j に対して、i+j 番目の箱から石をちょうど j 個取り除く。
ただし、N+k 番目と表される箱は k 番目の箱と同一視するものとする。
各操作において、取り除きたい個数の石がない箱があるときは、その操作を行えないことに注意してください。

-----問題ここまで----- */
/* -----解説等-----

貪欲にぶたんはあやしいねとおもったらN^2logNだった。TLEだね。

隣接項についてみればこれは-1,+n-1の組み合わせでできることが分かる。
したがって正しい数値の組み合わせでかつ、
差分も正しいものである必要がある。

----解説ここまで---- */

LL N;
LL a[200005];
LL ans = 0LL;
int fg = 0;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	LL sum = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		a[i + N] = a[i];
		sum += a[i];
	}
	if (sum % ((N + 1)*N/2) != 0) {
		cout << "NO" << endl;
		return 0;
	}

	fg = 1;
	LL k = sum / ((N + 1)*N/2);
	FOR(i, 0, N) {
		LL d = a[i + 1] - a[i];
		if ((k - d < 0) || (k - d) % N)fg = 0;
	}


	if(fg)
	cout << "YES" << "\n";
	else cout << "NO" << endl;
	return 0;
}

//TLE N^2logNだった

//LL N;
//LL a[100005];
//LL b[100005];
//LL ans = 0LL;
//
//int f(LL x, LL topindex) {
//
//	//cout << "f decsize: "<<x<<"  top index: "<<topindex << endl;
//	FOR(i, 0, N) {//copy
//		b[i] = a[i];
//	}
//	FOR(i, 0, N) {
//		b[i] -= x*((-topindex + i + 2 * N - 1) % N + 1);
//		if (b[i] < 0)return 0;
//	}
//	/*cout << "b[i]: ";
//	FOR(i, 0, N) {
//	cout << b[i] << " ";
//	}cout << endl;*/
//	FOR(i, 0, N) {
//		if (b[topindex] < b[i])return -1;
//	}
//	return 1;
//
//}
//
//int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//
//	cin >> N;
//	LL sum = 0;
//	FOR(i, 0, N) {
//		cin >> a[i];
//		sum += a[i];
//	}
//	cout << "start" << endl;
//	if (sum % ((N + 1)*N / 2) != 0) {
//		cout << "NO" << endl;
//		return 0;
//	}
//
//	LL topindex = 0;
//	LL topnum = -1;
//	int taira = 0;
//	int tairan = 0;
//	int zerof = 0;
//	int cnt = 0;
//	while (1) {
//		cnt++;
//		if (cnt>=N/100) {
//			FOR(i, 0, N) {
//				cout << a[i] << " ";
//			}cout << endl;
//		}
//		//cout << "loop::" << endl;
//		zerof = 1;
//		taira = 1;
//		topnum = -1;
//		topindex = -1;
//		FOR(i, 0, N) {
//			if (a[i] >= topnum) {
//				topindex = i;
//				topnum = a[i];
//			}
//			if (taira == 1 && a[i] % ((1 + N) * N / 2) == 0) {
//				taira = 1;
//				int temptaira = a[i] % ((1 + N) * N / 2);
//				if (i == 0)tairan = temptaira;
//
//				if (tairan != temptaira)taira = 0;
//			}
//			else taira = 0;
//
//			if (a[i] == 0 && zerof == 1) {
//				;
//			}
//			else if (a[i] > 0) {
//				zerof = 0;
//				continue;
//			}
//		}
//		//debug(topnum);
//		//debug(topindex);
//		if (zerof == 1 && taira==1) {
//			cout << "YES" << endl;
//			return 0;
//		}
//		LL l = 0, r = (LL)1e10;//回数
//		FOR(i, 0, 35) {
//			LL mid = (l + r) / 2;
//			if (f(mid, topindex)==1) {
//				l = mid;
//				//cout << "true" << endl;
//			}
//			else r = mid; //,cout << "false" << endl;
//						  //cout << "for l,r " << l << " " << r << endl;
//		}
//
//		int L = f(l, topindex); int R = f(l + 1, topindex);
//		if (L ==1 && R == -1)l++;
//		//cout <<"now l: "<< l << endl;
//		if (l == 0) {
//			cout << "NO" << endl;
//			return 0;
//		}
//		FOR(i, 0, N) {
//			a[i] -= l*((-topindex + i + 2 * N - 1) % N + 1);
//			if (a[i] < 0) {
//				cout << "NO" << endl;
//				return 0;
//			}
//		}
//
//
//	}
//
//	cout << "YES" << "\n";
//
//	return 0;
//}