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

/* -----  2017/06/27  Problem: ICPC2012国内予選C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1174&lang=jp  ----- */
/* ------問題------

パネルの左上の部分と連結されている同じ値がくっついている。
これの色を変更することで周りにある同色パネルをこれに結合する。
最大のパネルの大きさは。

-----問題ここまで----- */
/* -----解説等-----

5回しか変更できないので、6^5回すべての色変更を行う。
その最大値をとればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int h, w, c;

void pro(int n, vector<vector<int>>& temp) {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	int key = temp[1][1];
	temp[1][1] = n;
	bool usage[10][10] = { false };
	usage[1][1] = true;

	while (!q.empty()) {
		auto now = q.front(); q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; i++) {
			if (temp[x + dx[i]][y + dy[i]] == key) {
				if (usage[x + dx[i]][y + dy[i]] == true) continue;
				temp[x + dx[i]][y + dy[i]] = n;
				q.push({ x + dx[i], y + dy[i] });
				usage[x + dx[i]][y + dy[i]] = true;
			}
		}
	}
}

void Count(vector<vector<int>>& temp) {
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	bool usage[10][10] = { false };
	usage[1][1] = true;

	ll counta = 1;

	//for (int i = 1; i <= h; i++) {
	//	for (int j = 1; j <= w; j++) {
	//		cout << temp[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;


	while (!q.empty()) {
		auto now = q.front(); q.pop();
		int x = now.first, y = now.second;
		for (int i = 0; i < 4; i++) {
			if (temp[x + dx[i]][y + dy[i]] == c) {
				if (usage[x + dx[i]][y + dy[i]] == true) continue;
				counta++;
				q.push({ x + dx[i], y + dy[i] });
				usage[x + dx[i]][y + dy[i]] = true;
			}
		}
	}

	ans = max(ans, counta);
}

void dfs(int n,vector<vector<int>>p) {
	if (n == 5) {
		Count(p);
		return;
	}

	if (n == 4) {
		auto temp = p;
		pro(c, temp);
		dfs(n + 1, temp);
		return;
	}
	for (int i = 1; i <= 6; i++) {
		auto temp = p;
		pro(i, temp);

		/*if (n == 1) {
			for (int i = 1; i <= h; i++) {
				for (int j = 1; j <= w; j++) {
					cout << temp[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}*/

		dfs(n + 1, temp);
	}
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
	  cin >> h >> w >> c;
	  if (h == 0 && w == 0 && c == 0) break;
	  ans = 0;
	  vector<vector<int>> p(h + 2, vector<int>(w + 2, -1));

	  for (int i = 1; i <= h; i++) for (int j = 1; j <= w; j++) cin >> p[i][j];

	  /*for (int i = 1; i <= h; i++) {
		  for (int j = 1; j <= w; j++) {
			  cout << p[i][j] << " ";
		  }
		  cout << endl;
	  }*/


	  dfs(0, p);

	  cout << ans << endl;
  }
  return 0;
}
