#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
/* -----  2017/03/22  Problem: RUPC2017 C / Link:
* http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=C
*/
/* ------���------

�����N�Q��

-----��肱���܂�----- */
/* -----�����-----

T�ɑ΂��Ă͊m��p�ő@�ۂł��邩��J�ډߒ���cost*p��df���Ă����΂悢�B
����t���N�^����T'�ł͂�����v�Z����̂͑�ςȂ̂�T�̒��_�񓯂����Ғl�������邱�Ƃ��킩���
������x�d�݂𑝂��Ȃ���dfs������΂悢�B

----��������܂�---- */

typedef pair<int, double> P;

vector<P> e[100001];

double sum;
double p;

bool vis[100001];

double dfs(int i, double c) {
  if (vis[i])
    return 0;
  vis[i] = 1;
  double cost = c;
  for (auto &j : e[i]) {
    cost += dfs(j.first, j.second) * p;
  }
  return cost;
}

double dfs2(int i, double c) {
  if (vis[i])
    return 0;
  vis[i] = 1;
  double cost = c + sum;
  for (auto &j : e[i]) {
    cost += dfs2(j.first, j.second) * p;
  }
  return cost;
}

signed main() {

  cin >> p;

  int n;
  cin >> n;

  rep(i, n - 1) {
    int x, y, c;
    cin >> x >> y >> c;
    e[x].push_back(P(y, c));
    e[y].push_back(P(x, c));
  }

  rep(i, n + 1) vis[i] = 0;

  sum = dfs(1, 0);

  rep(i, n + 1) vis[i] = 0;

  double ans = dfs2(1, 0);

  printf("%.10lf\n", ans);

  return 0;
}