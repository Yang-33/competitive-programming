#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
#include <functional>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
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
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/25  Problem: disco_nagano2017_d / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

†気合†

----解説ここまで---- */
//	以下のデータを使用して問題を解いてください。
//	変数名・データ型は任意
//	mainのローカル変数として定義してください。
//	ステージは４ステージ

//	ステージ１
int	Q4_1[12][12] = {
{ 0,1,0,0,0,0,0,1,1,1,0,0 },
{ 1,1,1,1,0,0,0,1,0,1,0,1 },
{ 0,1,1,1,0,1,1,1,1,1,1,1 },
{ 0,0,0,1,0,1,1,0,0,1,0,1 },
{ 0,0,0,1,1,1,1,1,1,1,0,1 },
{ 1,1,1,1,0,0,0,0,0,1,0,1 },
{ 1,0,0,1,0,1,1,1,0,1,0,1 },
{ 1,0,0,1,0,1,0,0,0,1,0,1 },
{ 1,1,1,1,0,1,1,0,0,1,0,0 },
{ 0,1,0,1,0,0,0,0,1,1,0,0 },
{ 0,1,0,1,1,1,1,1,1,1,1,1 },
{ 0,0,0,0,1,0,0,0,0,0,0,0 },
}; //1

//	ステージ２
int	Q4_2[12][12] =
{
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1,0,0,0,0,0,1,0,0,0,0,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 0,0,1,0,0,0,1,0,0,0,1,1 },
	{ 1,0,1,0,1,1,1,1,1,0,1,0 },
	{ 1,0,1,0,1,0,0,0,1,0,1,0 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0 },
	{ 1,0,1,0,1,0,0,0,1,0,1,0 },
	{ 1,0,1,0,1,0,1,0,1,0,1,1 },
	{ 1,0,1,0,1,0,0,0,1,0,1,0 },
	{ 1,0,1,0,1,1,1,1,1,0,1,0 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1 },
};//1has 2

//	ステージ３
int	Q4_3[12][12] = {
{ 1,1,1,1,1,1,1,1,1,1,1,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,1,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,1,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,0,0,0,0,0,0,0,0,0,0,1 },
{ 1,1,1,1,1,1,1,1,1,1,1,1 },
};

//	ステージ４
int	Q4_4[12][12] =
{
	{ 1,1,1,1,1,1,1,1,1,1,1,0 },
	{ 1,0,0,0,1,0,0,0,0,0,1,0 },
	{ 1,0,1,0,1,0,1,0,1,0,1,0 },
	{ 1,0,0,0,0,0,1,0,0,0,1,0 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,1,0,1,0,1,0,0,1 },
	{ 1,0,1,0,1,0,1,0,0,0,0,1 },
	{ 1,1,1,0,0,0,1,0,1,1,0,1 },
	{ 1,0,1,1,0,1,1,0,0,0,0,1 },
	{ 1,0,0,0,0,0,1,1,1,1,1,1 },
	{ 1,1,1,1,0,1,1,0,0,0,1,1 },
}; //2

LL N;

LL ans = 0LL;

const int OUT = -1;
inline bool IN(int y, int x, int H, int W) { return (0 <= y&&y < H && 0 <= x&&x < W); }

int bfs2D(pair<int, int> s, int masu[14][14], int Height, int Width, vector<vector<int> > & visit) {

	queue<pair<int, int>>q;
	q.push(s);
	visit[s.first][s.second] = 1;
	masu[s.first][s.second] = OUT;

	while (!q.empty()) {
		PII a = q.front(); q.pop();
		int y = a.first, x = a.second;
		FOR(k, 0, 4) { //辺が存在するかはチェックしてないよ
			int ny = y + DY[k]; int nx = x + DX[k];
			if (IN(ny, nx, Height, Width)) {
				if (masu[ny][nx] == 0 && visit[ny][nx] == 0) {// 辺の チェックしてるよ
					q.push(pair<int, int>(ny, nx));
					visit[ny][nx] = 1;
					masu[ny][nx] = OUT;
				}
			}
		}
	}

}




int main() {
	/*cin.tie(0);
	ios_base::sync_with_stdio(false);*/
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int	Q4_1[12][12] = {
		{ 0,1,0,0,0,0,0,1,1,1,0,0 },
		{ 1,1,1,1,0,0,0,1,0,1,0,1 },
		{ 0,1,1,1,0,1,1,1,1,1,1,1 },
		{ 0,0,0,1,0,1,1,0,0,1,0,1 },
		{ 0,0,0,1,1,1,1,1,1,1,0,1 },
		{ 1,1,1,1,0,0,0,0,0,1,0,1 },
		{ 1,0,0,1,0,0,0,0,0,1,0,1 },
		{ 1,0,0,1,0,0,0,0,0,1,0,1 },
		{ 1,1,1,1,0,0,0,0,0,1,0,0 },
		{ 0,1,0,1,0,0,0,0,1,1,0,0 },
		{ 0,1,0,1,1,1,1,1,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0,0,0,0,0 },
	}; //40

	//	ステージ１
	//int	Q4_1[12][12] = {
	//	{ 0,1,0,0,0,0,0,1,1,1,0,0 },
	//	{ 1,1,1,1,0,0,0,1,0,1,0,1 },
	//	{ 0,1,1,1,0,1,1,1,1,1,1,1 },
	//	{ 0,0,0,1,0,1,1,0,0,1,0,1 },
	//	{ 0,0,0,1,1,1,1,1,1,1,0,1 },
	//	{ 1,1,1,1,0,0,0,0,0,1,0,1 },
	//	{ 1,0,0,1,0,1,1,1,0,1,0,1 },
	//	{ 1,0,0,1,0,1,0,0,0,1,0,1 },
	//	{ 1,1,1,1,0,1,1,0,0,1,0,0 },
	//	{ 0,1,0,1,0,0,0,0,1,1,0,0 },
	//	{ 0,1,0,1,1,1,1,1,1,1,1,1 },
	//	{ 0,0,0,0,1,0,0,0,0,0,0,0 },
	//}; //1
	//int	Q4_1[12][12] = {
	//	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,0,1,1,1,1,1,1,1,0,0 },
	//	{ 0,0,0,1,0,0,0,0,0,1,0,0 },
	//	{ 0,0,0,1,0,1,1,1,0,1,0,0 },
	//	{ 0,0,0,1,0,1,0,0,0,1,0,0 },
	//	{ 0,0,0,1,0,1,1,0,0,1,0,0 },
	//	{ 0,0,0,1,0,0,0,0,0,1,0,0 },
	//	{ 0,0,0,1,1,1,1,1,1,1,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	//	{ 0,0,0,0,0,0,0,0,0,0,0,0 }
	//}; //1

	//	ステージ２
	int	Q4_2[12][12] =
	{
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1,0,0,0,0,0,1,0,0,0,0,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,0 },
		{ 0,0,1,0,0,0,1,0,0,0,1,1 },
		{ 1,0,1,0,1,1,1,1,1,0,1,0 },
		{ 1,0,1,0,1,0,0,0,1,0,1,0 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0 },
		{ 1,0,1,0,1,0,0,0,1,0,1,0 },
		{ 1,0,1,0,1,0,1,0,1,0,1,1 },
		{ 1,0,1,0,1,0,0,0,1,0,1,0 },
		{ 1,0,1,0,1,1,1,1,1,0,1,0 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
	};//1has 2

	  //	ステージ３
	int	Q4_3[12][12] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,1,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
	};

	//	ステージ４
	int	Q4_4[12][12] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,0 },
		{ 1,0,0,0,1,0,0,0,0,0,1,0 },
		{ 1,0,1,0,1,0,1,0,1,0,1,0 },
		{ 1,0,0,0,0,0,1,0,0,0,1,0 },
		{ 1,0,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,1,0,0,0,1,0,0,0,0,1 },
		{ 1,0,1,0,1,0,1,0,1,0,0,1 },
		{ 1,0,1,0,1,0,1,0,0,0,0,1 },
		{ 1,1,1,0,0,0,1,0,1,1,0,1 },
		{ 1,0,1,1,0,1,1,0,0,0,0,1 },
		{ 1,0,0,0,0,0,1,1,1,1,1,1 },
		{ 1,1,1,1,0,1,1,0,0,0,1,1 },
	}; //2


	ans = 0;
	N = 14;
	VVI visitz(14, VI(14, 0));
	queue<PII>q;
	// 外側の0を-1で埋める
	int banmen[14][14] = { {0} };
	FOR(i, 0, 12) {
		FOR(j, 0, 12) {
			banmen[i + 1][j + 1] = Q4_1[i][j];
		}
	}

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == 0 || j == 0 || i == 13 || j == 13) {
				if (visitz[i][j])continue;
				else if (Q4_1[i][j] == 0 && visitz[i][j] == 0)
					bfs2D(PII(i, j), banmen, N, N, visitz);
			}
		}
	}
	//FOR(i, 0, N) {
	//	FOR(j, 0, N) {
	//		cout << banmen[i][j] << " ";
	//	}cout << endl;
	//}
	FOR(i, 0, 14) {
		FOR(j, 0, 14) {
			printf("%02d ", banmen[i][j]);
		}printf("\n");
	}
	LL aaa = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (banmen[i][j] == 1) {
				int cntbit = 0;
				int cnt = 0;
				FOR(k, 0, 4) {
					int ny = i + DY[k], nx = j + DX[k];
					if (IN(ny, nx, N, N)) {
						if (banmen[ny][nx] == 1) {
							cntbit |= 1 << k;
							cnt++;
						}
					}
				}
				if (cntbit == 3 || cntbit == 12)continue;
				if (cnt == 3) {// out ? zero?
					cout << i << "," << j << endl;
					debug(ans);
					int zero = 0;
					int out = 0;
					FOR(k, 4, 8) {
						int ny = i + DY[k], nx = j + DX[k];
						if (IN(ny, nx, N, N)) {
							if (banmen[ny][nx] == OUT)out++;
							if (banmen[ny][nx] == 0)zero++;
						}
					}
					cout << out << " " << zero << endl;
					if (out + zero == 5) {// 0,1,2
						if (zero == 5 || out == 5)ans += 2;
						else if (out == 4||zero==4)ans += 1;
						else if (out == 3)ans += 0;
						else if (zero == 3)ans += 2;

					}
					debug(ans);
					continue;
				}
				if (cnt == 4) {
					int zero = 0;
					int out = 0;
					FOR(k, 4, 8) {
						int ny = i + DY[k], nx = j + DX[k];
						if (IN(ny, nx, N, N)) {
							if (banmen[ny][nx] == OUT)out++;
							if (banmen[ny][nx] == 0)zero++;
						}
					}
					//	cout << out << " " << zero << endl;
					if (out > 0)ans += out;
					else ans += zero;
					continue;
				}
				if (cnt == 0) { ans += 4; continue; }
				if (cnt == 1) {
					int out = 0;
					int zero = 0;
					int diff = 0;
					FOR(k, 0, 8) {
						int ny = i + DY[k], nx = j + DX[k];
						if (IN(ny, nx, N, N)) {
							if (banmen[ny][nx] == OUT)out = 1;
							if (banmen[ny][nx] == 0)zero = 1;
						}
					}
					//cout << out << " " << zero << endl;
					//debug(ans);
					if (out&&zero)diff = 1;
					if (diff == 1)continue;
					ans += 2;
					//debug(ans);
					continue;
				}
				if (cnt == 2) { // 0,1,2
					int zero = 0;
					int out = 0;
					FOR(k, 4, 8) {
						int ny = i + DY[k], nx = j + DX[k];
						if (IN(ny, nx, N, N)) {
							if (banmen[ny][nx] == OUT)out++;
							if (banmen[ny][nx] == 0)zero++;
						}

					}
					//debug(ans);
					//cout << out << " " << zero << endl;
					if (out == 4 || zero == 4) {ans += 2; }
					else if (out + zero == 4)ans += 1;
					//debug(ans);
					continue;

				}

			}
		}
	}



	cout << ans << endl;
	return 0;
}
