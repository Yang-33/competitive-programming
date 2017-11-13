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

/* -----  2017/11/13  Problem: NU_27_A AOJ1252  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1252  ----- */
/* ------問題------

文字列の編集距離を考える。
削除挿入置換、隣接文字のswapのコストを1とする。
このときコストがD以下の文字列を辞書順最小のペアで出力せよ。

-----問題ここまで----- */
/* -----解説等-----

編集距離2は組み合わせがかなり多いが、編集距離とは何だったかを考えると、
D=2のときは文字列s,tの編集距離が1のもので一致するものがあればよいことになる。
あとは頑張って高速化をする。
隣接をちゃんと見てなかったので時間が溶けた

----解説ここまで---- */

void get_dist1(string &s, set<string>&a) {
	a.insert(s);
	FOR(i, 0, SZ(s)) {//delete
		a.insert(s.substr(0, i) + s.substr(i + 1));
	}
	FOR(i, 0, SZ(s) - 1) {//swap
		swap(s[i], s[i + 1]);
		a.insert(s);
		swap(s[i], s[i + 1]);
	}
	FOR(i, 0, SZ(s)) {//replace
		char c = s[i];
		FOR(j, 0, 26) {
			s[i] = 'a' + j;
			a.insert(s);
		}
		s[i] = c;
	}
	//insert
	FOR(i, 0, 26)a.insert(s + (char)('a' + i));
	FOR(i, 0, SZ(s)) {
		FOR(j, 0, 26)
			a.insert(s.substr(0, i) + (char)('a' + j) + s.substr(i));
	}

}
//
//void gen_set(string s, set<string> &d)
//{
//	d.clear();
//
//	// delete
//	for (int i = 0; i < s.length(); i++) {
//		string tmp;
//		for (int j = 0; j < s.length(); j++)
//			if (i != j) tmp += s[j];
//		d.insert(tmp);
//	}
//
//	// insert
//	for (int i = 0; i <= s.length(); i++) {
//		for (char c = 'a'; c <= 'z'; c++) {
//			string tmp;
//			for (int j = 0; j < s.length(); j++) {
//				if (i == j) tmp += c;
//				tmp += s[j];
//			}
//			if (i == s.length()) tmp += c;
//			d.insert(tmp);
//		}
//	}
//
//	// replace
//	for (int i = 0; i < s.length(); i++) {
//		for (char c = 'a'; c <= 'z'; c++) {
//			string tmp = s;
//			tmp[i] = c;
//			d.insert(tmp);
//		}
//	}
//	//FOR(i, 0, SZ(s)) {//swap
//	//	FOR(j, i + 1, SZ(s)) {
//	//		swap(s[i], s[j]);
//	//		d.insert(s);
//	//		swap(s[j], s[i]);
//	//	}
//	//}
//
//	// swap
//	for (int i = 0; i < s.length() - 1; i++) {
//		string tmp = s;
//		swap(tmp[i], tmp[i + 1]);
//		d.insert(tmp);
//	}
//
//	d.insert(s);
//}
//int matching2(string&s, string&t) {
//	/* edit dist <=1を作成 */
//	set<string>a(get_dist1(s));
//	set<string>b(get_dist1(t));
//	for (string s : a)if(b.find(s)!=b.end())return true;
//	return false;
//}
//int matching2(string&s, string&t) {
//	/* edit dist <=1を作成 */
//	set<string>a(get_dist1(s));
//	int SZA = SZ(a);
//	set<string>b(get_dist1(t));
//	int SZB = SZ(b);
//	for (string s : a)b.insert(s);
//	int SZM = SZ(b);
//	if (SZM == SZB + SZA)return false;
//	else return true;
//}
//int matching1(string&s, string&t) {
//	/* edit dist <=1を作成 */
//	set<string>b(get_dist1(s));
//	set<string>a; a.insert(t);
//	int SZB = SZ(b);
//	int SZA = SZ(a);
//	for (string ss : a)b.insert(ss);
//	int SZM = SZ(b);
//	if (SZM == SZB + SZA)return false;
//	else return true;
//}

int matching(int i, int j, int d, const VS& vs, const vector<set<string>>&vseset) {
	/* edit dist <=1を作成 */
	if (d == 1) {
		if (vseset[i].find(vs[j]) != vseset[i].end())return true;
		else return false;
	}
	else {
		if (vseset[i].size() < vseset[j].size())swap(i, j);
		for (string s : vseset[j]) {
			if (vseset[i].find(s) != vseset[i].end())return true;
		}
		return false;
	}
}
//int matching(string &s, string &t, int d) {
//	return (d == 1 ? matching1(s, t) : matching2(s, t));
//}
int N;
int dp[17][17];
//
//int func_dp(string&s, string&t, int d) {
//	int SZ_S = SZ(s);
//	int SZ_T = SZ(t);
//	fill(*dp, *dp + 17 * 17, 100);
//	// 0はまだどれもswapしてない
//	/*VVI ruis(SZ_S + 1, VI(26, 0));
//	VVI ruit(SZ_T + 1, VI(26, 0));*/
//	FOR(i, 0, SZ_S + 1) {
//		dp[i][0] = i;
//	}
//	FOR(j, 0, SZ_T + 1) {
//		dp[0][j] = j;
//	}
//	/*FOR(i, 0, SZ_S) {
//		FOR(j, 0, 26)
//			ruis[i + 1][j] += ruis[i][j] + (s[i] == ('a' + j) ? 1 : 0);
//	}
//	FOR(i, 0, SZ_T) {
//		FOR(j, 0, 26)
//			ruis[i + 1][j] += ruis[i][j] + (t[i] == ('a' + j) ? 1 : 0);
//	}*/
//	int INDEX_T = 0;
//	int c = 0;
//	FOR(i, 1, SZ_S + 1) {
//		FOR(j, 1, SZ_T + 1) {
//			if (s[i] != t[j])c = 1;
//			else c = 0;
//			dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + c);
//			dp[i][j] = min(dp[i][j], dp[i - 1][j] + c);
//			dp[i][j] = min(dp[i][j], dp[i][j - 1] + c);
//		}
//	}
//	FOR(k, 0, 26) {
//		if (dp[SZ_S][SZ_T] <= d)return 1;
//	}
//	return 0;
//}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	while (cin >> N, N) {
		int d; cin >> d;
		VS orig(N);
		string ss;
		vector<set<string>>vseset(N, set<string>());
		FOR(i, 0, N) {
			cin >> orig[i];
			get_dist1(orig[i], vseset[i]);
		}
		vector<pair<string, string>>se;
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				if (matching(i, j, d, orig, vseset)) {
					if (orig[i] < orig[j])
						se.push_back(pair<string, string>(orig[i], orig[j]));
					else
						se.push_back(pair<string, string>(orig[j], orig[i]));

				}
			}
		}

		int ans = SZ(se);
		SORT(se);
		FOR(i, 0, ans) {
			cout << se[i].first << "," << se[i].second << endl;
		}
		cout << ans << endl;
	}
	//printf("%s\n", str);


	return 0;
}