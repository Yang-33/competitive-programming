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

/* -----  2018/06/16  Problem: AOJ 2399 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2399  ----- */
/* ------問題------

ICPC (International Committee of Privacy and Confidence) は世界中に多くの構成員を持つ組織であり、その名の通り非常にプライバシーを尊重する、秘密主義者たちの団体である。構成員たちは必要上他の構成員の個人情報を知ってしまうことがあるが、それらを厳重に秘匿するよう義務付けられている。
しかしある日、何人かの構成員の個人情報が漏洩してしまった！ICPCの ACM (Account Control Manager: アカウント管理責任者) であるあなたは、速やかに情報を漏洩させた構成員を特定し、厳重に処分しなければならない。
あなたは構成員よりも大きな権限を持つ管理者なので、誰が誰の個人情報を知ってしまっているかを完全に把握している。もちろん、どの構成員も自分の知らない構成員の個人情報を漏洩させることはありえない。しかし、犯人は自分が知っている全ての個人情報を漏洩させたとは限らない。個人情報が漏洩してしまった構成員の一覧から、どの構成員が個人情報を漏洩させたのかを (可能ならば) 特定しよう。

-----問題ここまで----- */
/* -----解説等-----

検索と判定をすれば良い。setが楽かな？

----解説ここまで---- */


void solve() {

	int N;
	while (cin >> N, N) {
		vector<set<int>>a(N);
		FOR(i, 0, N) {
			int m; cin >> m;
			FOR(j, 0, m) {
				int p; cin >> p;
				a[i].insert(p);
			}
		}
		int Ks; cin >> Ks;
		VI k(Ks);
		FOR(i, 0, Ks) {
			cin >> k[i];
		}
		int cnt = 0;
		int id = -1;
		FOR(i, 0, N) {
			int ok = 1;
			FOR(j, 0, Ks) {
				if (a[i].count(k[j]))ok &= 1;
				else ok &= 0;
			}
			if (ok) {
				cnt++;
				id = i + 1;
			}
		}
		if (cnt == 1) {
			cout << id << endl;
		}
		else {
			cout << -1 << endl;
		}

	}

}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}
