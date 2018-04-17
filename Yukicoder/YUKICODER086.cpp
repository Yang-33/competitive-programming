#include <bits/stdc++.h>
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

/* -----  2018/04/17  Problem: yukicoder 086  / Link: http://yukicoder.me/problems/no/086  ----- */
/* ------問題------

yuki君は旅行先でテレビを見ようとした。
旅行先のテレビのリモコンには、ボタンが縦N段、横M列の長方形状に計N×M個並んでおり、それぞれを押すとテレビの表示が対応するチャンネルに切り替わる。
しかし、この地方のテレビでは視聴可能なチャンネルと視聴できないチャンネルとがあった。

yuki君は視聴可能なチャンネルだけをすべて巡回したくなった。
ただし、yuki君は旅行で疲れているので、複雑な順番でボタンを押したくない。
そこで、yuki君は以下のルールで順にボタンを押す事を考えた。

最初は任意の視聴可能なチャンネルのボタンを押すことができる。そして次に押すボタンを上下左右いずれかに隣接するボタンのうちから１つ選択する。
以降、隣接するボタンを順に押していく。その際、次に押すボタンは、前と同じ向きに移動した先にあるボタンか、向きを左に90度回転した先にあるボタンのいずれかを選択する。
（たとえば、今押したボタンが１つ前に押したボタンの上にある場合、次に押せるのはもう１つ上にあるボタンか、左にあるボタンのどちらかである。）
視聴できないチャンネルのボタンは押してはならない。
視聴可能なチャンネルのボタンを全てちょうど１回ずつ押し、最後に最初に押したボタンを押す。（例外として、最初に押したボタンだけは最後と合わせ２回押してよい）

入力としてN, M, 各ボタンに対応するチャンネルの視聴可否が与えられたとき、上記ルールをすべて満たすボタンの押し順が存在するか答えよ。

-----問題ここまで----- */
/* -----解説等-----

実装苦手マンだ…まずいなあ  
一周して戻ってくるしかないことに気がつく。ただし始点を変えることで一回だけ凹んだ回り方も許される。  
したがって右優先探索をすれば良い。(取ってつけたような名前)  
結果、右に曲がった回数が1以下で全部の頂点を訪問していれば良い。  

----解説ここまで---- */

LL ans = 0LL;
int DY[] = { 1,0,-1,0 };
int DX[] = { 0,-1,0,1 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W; cin >> H >> W;
	VS m(H);
	FOR(i, 0, H) {
		cin >> m[i];
	}
	PII S = PII(INF, INF);
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (m[i][j] == '.')S = min(S, PII(i, j));
		}
	}
	int sy = S.first, sx = S.second;
	auto isValid = [&](int y, int x) -> bool {
		return 0 <= y && y < H && 0 <= x && x < W&&m[y][x] == '.';
	};

	int dir = 0;
	int y = sy, x = sx;
	int cntL = 0, cntR = 0;
	while (1) {

		while (isValid(y + DY[dir], x + DX[dir])) {
			y += DY[dir], x += DX[dir];
			m[y][x] = '#';
		}
		int ld = (dir + 3) % 4;
		int rd = (dir + 1) % 4;

		if (isValid(y + DY[rd], x + DX[rd])) {
			dir = rd;
			cntR++;
		}else if (isValid(y + DY[ld], x + DX[ld])) {// 左に曲がる
			dir = ld;
			cntL++;
		}
		else {
			break;
		}
	}
	int dat = 0;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			dat += m[i][j] == '.';
		}
	}
	if (cntR <= 1 && dat == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << "\n";

	}

	return 0;
}
