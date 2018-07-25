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

/* -----  2018/07/26  Problem: AOJ 0262 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0262  ----- */
/* ------問題------

太郎君は、子供会の催しでみんなで遊べるようにすごろくを作りました。ゲームをおもしろくするために、「ふりだし」と「あがり」以外のすごろくのマスのいくつかに「６つ進む」、「５つ戻る」のように指示を書き込んでいきました。ルーレットを回して出た数だけ進み、止まったマスに指示が書き込んであれば、その指示に従って移動します。ただし、指示に従って進んだ先のマスの指示には従いません。
ルーレットは１からある数までの間の数を等確率で出すことができるものとします。また、「あがり」に達するより大きな数が出たときや、指示に従うと「あがり」より先に進んでしまうときは「あがり」に移動します。指示に従って戻るときに「ふりだし」より前に戻ってしまうときは「ふりだし」に戻ることにします。

ところが、ルーレットとマスの指示によっては「あがり」にたどりつけない場合が出てきてしまいます。たとえば、図のようなすごろくを作ったとしましょう。１と２しか出ないルーレットを使うと、１，２の順に出れば「あがり」に行けますが、はじめに２が出たらその後は何が出ても永久に「あがり」にはたどり着けません。太郎君は、そうとは知らずに調子に乗ってあちこちのマスに指示を書き込んでしまいました。
そこで、太郎君に代わって、ルーレットとマスの指示によっては、「あがり」にたどり着けない場合が生じるかどうか判定するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

頭がないのでワーシャルフロイドに踏み切れず。
可能性を全探索すればよい…

----解説ここまで---- */

using LL = long long; template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;


// a 1index
void bfs(const VV<int>&G, const VV<int>&rG, const V<int>&a, VV<int>&fl) {
	int N = SZ(a);
	FOR(r, 0, 2) {
		int s = !r ? 0 : N;
		fl[r][s] = 1;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			FOR(i, 0, (!r ? SZ(G[v]) : SZ(rG[v]))) {
				int to = (!r ? G[v].at(i) : rG[v].at(i));
				if (!fl[r][to]) {
					fl[r][to] = true;
					q.push(to);
				}
			}
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// OK NO のみ
	// back DP的なことをする
	int Hi;
	while (cin >> Hi, Hi) {
		int N; cin >> N;
		V<int>a(N + 1, 0);
		FOR(i, 0, N) {
			cin >> a[i + 1];
		}
		VV<int>G(N + 2);
		VV<int>rG(N + 2);
		VV<int>fl(2, V<int>(N + 2, 0));
		FOR(i, 0, N + 1) {
			FOR(j, 1, Hi + 1) {
				int add = i + j;
				int to = (add<N + 1 ? add + a.at(i + j) : add);
				to = max(to, 0);
				to = min(to, N + 1);
				G[i].push_back(to);
				rG[to].push_back(i);
			}
		}
		bfs(G, rG, a, fl);
		int flag = 0;
		FOR(i, 0, N + 2) {
			if (fl[0][i] && !fl[1][i]) {
				flag = 1;
				break;
			}
		}
		cout << (flag ? "NG" : "OK") << endl;

	}
	return 0;
}