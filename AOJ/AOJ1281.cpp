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

/* -----  2018/06/16  Problem: AOJ 1281 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1281  ----- */
/* ------問題------

3つ同時にゴールを目指す。
重なってはいけない。
最短時間は？

-----問題ここまで----- */
/* -----解説等-----

なんでsample2通らんねん

----解説ここまで---- */

int dist[256][256][256];
using PII = pair<int, int>;
const PII NoUse = PII(0, 0);

void solve() {
	int  W, H, N;
	while (cin >> W >> H >> N, W || H) {
		string s; getline(cin, s);
		vector<string>vs(H);
		PII sa = NoUse, sb = NoUse, sc = NoUse;
		PII ta = NoUse, tb = NoUse, tc = NoUse;
		FOR(i, 0, H) {
			getline(cin, vs[i]);
			FOR(j, 0, W) {
				if (vs[i][j] == 'a') {
					vs[i][j] = ' ';
					sa = PII(i, j);
				}
				else if (vs[i][j] == 'b') {
					vs[i][j] = ' ';
					sb = PII(i, j);
				}
				else if (vs[i][j] == 'c') {
					vs[i][j] = ' ';
					sc = PII(i, j);
				}
				else if (vs[i][j] == 'A') {
					vs[i][j] = ' ';
					ta = PII(i, j);
				}
				else if (vs[i][j] == 'B') {
					vs[i][j] = ' ';
					tb = PII(i, j);
				}
				else if (vs[i][j] == 'C') {
					vs[i][j] = ' ';
					tc = PII(i, j);
				}
			}
		}

		fill(**dist, **dist + 256 * 256 * 256, INF);
		using tp = tuple<PII, PII, PII>;
		queue<tp>q;
		q.push(tp(sa, sb, sc));
		auto ha = [&](const PII & x) { // pair<int,int>のhash値的なもの(配列のアクセス用)
			return x.first*H + x.second;
		};
		int dy[4] = { -1,0,1,0 };
		int dx[4] = { 0,1,0,-1 };

		auto f = [&](const PII & a) {// stayを含めた次状態の生成
			vector<PII>res;
			res.push_back(a);
			if (a == NoUse)return res;
			FOR(p, 0, 4) {
				int ny = a.first + dy[p], nx = a.second + dx[p];
				if (0 <= ny && ny < H && 0 <= nx && nx < W) {
					if (vs[ny][nx] != '#') {
						res.push_back(PII(ny, nx));
					}
				}
			}
			return res;
		};

		dist[ha(sa)][ha(sb)][ha(sc)] = 0;
		int ans = 0;
		// O(H^6*(UNCHI))

		while (!q.empty()) {
			PII aa, bb, cc;
			tie(aa, bb, cc) = q.front(); q.pop();

			int d = dist[ha(aa)][ha(bb)][ha(cc)];

			// nx stateを全部持ってくる
			vector<PII>na = f(aa), nb = f(bb), nc = f(cc);

			FOR(i, 0, SZ(na)) {
				PII a = na[i];
				FOR(j, 0, SZ(nb)) {
					PII b = nb[j];
					FOR(k, 0, SZ(nc)) {// 重複しない、swapされないもののみ遷移させる
						PII c = nc[k];

						// - 重複、ただし未使用はアレ
						if (((a != NoUse) && (a == b || a == c)))continue;
						if (((b != NoUse) && (b == c)))continue;
						// a,b a,c b,c

						// ここでゆるさないものをはじく
						// - swap
						if (a != NoUse && aa == b && bb == a)continue; // a,b
						if (a != NoUse && aa == c && cc == a)continue; // a,c
						if (b != NoUse && bb == c && cc == b)continue; // b,c

						if (dist[ha(a)][ha(b)][ha(c)] > d + 1) {
							dist[ha(a)][ha(b)][ha(c)] = d + 1;
							q.push(tp(a, b, c));
							if (ta == a && tb == b && tc == c) {
								ans = d + 1;
								break;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {

	solve();
}