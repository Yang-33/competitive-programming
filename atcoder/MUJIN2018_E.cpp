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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { -1, 1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/04  Problem: mujin2018 E / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	string d; cin >> d;
	VS  vs(N);
	PII ss, tt;

	FOR(i, 0, N) {
		cin >> vs[i];
		FOR(j, 0, M) {
			if (vs[i][j] == 'S')ss = PII(i, j);
			if (vs[i][j] == 'G')tt = PII(i, j);
		}
	}

	// 速くいっても損はしない
	LL ans = LINF;

	VVL table(K, VL(4, INF));
	// t%Kのときの遷移は1こ
	string t = d + d;
	map<char, LL>Map;
	auto ff = [](char c) {
		if (c == 'U')return 0;
		if (c == 'D')return 1;
		if (c == 'R')return 2;
		if (c == 'L')return 3;
	};
	string UDRL = "UDRL";
	FOR(i, 0, 4) {
		Map[(UDRL[i])] = INF;
	}
	FORR(i, SZ(t) - 1, 0 - 1) {
		Map[t[i]] = i;
		int tu = Map[(UDRL[0])] - i;
		int td = Map[(UDRL[1])] - i;
		int tr = Map[(UDRL[2])] - i;
		int tl = Map[(UDRL[3])] - i;
		if (i < SZ(d)) {
			table[i][ff(UDRL[0])] = tu;
			table[i][ff(UDRL[1])] = td;
			table[i][ff(UDRL[2])] = tr;
			table[i][ff(UDRL[3])] = tl;
		}
	}

	//幅
	// tableをみて1e8より大きいときはカット
	using tp = tuple<LL, LL, LL>;
	priority_queue<tp, vector<tp>, greater<tp>>pq;
	pq.push(tp(0, ss.first, ss.second));// y,x
	int H = N, W = M;
	VVL dist(H, VL(W, LINF));
	dist[ss.first][ss.second] = 0;
	while (!pq.empty()) {
		LL t, y, x; tie(t, y, x) = pq.top(); pq.pop();
		if (dist[y][x] < t)continue;
		if (PII(y, x) == tt) {
			ans = min(ans, t);
			continue;
		}
		int tim = t %K;
		FOR(k, 0, 4) {
			int ny = y + DY[k], nx = x + DX[k];
			if (0 <= ny&&ny < H && 0 <= nx && nx < W) {
				if (vs[ny][nx] == '#')continue;
				LL cost = table[tim][k];
				if (cost > SZ(d))continue;
				LL nd = t + cost + 1;

				if (dist[ny][nx] > nd) {
					dist[ny][nx] = nd;
					pq.push(tp(nd, ny,nx));
				}
			}
		}
	}

	if (ans == LINF)ans = -1;
	cout << ans << "\n";

	return 0;
}
