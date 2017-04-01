#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/03/31  Problem: JOI予選 2009 4  / Link: https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t4/2009-yo-t4.html  ----- */
/* ------問題------

冬の寒いある日，JOI太郎君は広場にはった薄氷を割って遊ぶことにした．
広場は長方形で， 東西方向に m 個， 南北方向に n 個， つまり， m × n の区画に区切られている． 
また， 薄氷が有る区画と無い区画がある． JOI太郎君は，次のルールにしたがって，薄氷を割りながら区画を移動することにした．
薄氷があるどの区画からも薄氷を割り始めることができる．
東西南北のいずれかの方向に隣接し， まだ割られていない薄氷のある区画に移動できる．
移動した先の区画の薄氷をかならず割る．
JOI太郎君が薄氷を割りながら移動できる区画数の最大値を求めるプログラムを作成せよ．
ただし， 1 ≦ m ≦ 90，1 ≦ n ≦ 90 である． 与えられる入力データでは， 移動方法は20万通りを超えない．

-----問題ここまで----- */
/* -----解説等-----

dfsで最大値を更新していく感じでやればよい。
氷の板を使えなくするのでそのようにし、以後は使えるように復元することができればよい。

----解説ここまで---- */

ll w,h;
bool ice[100][100];
ll ans = 0LL;

ll dfs(ll y, ll x) {
    if (ice[y][x] == 0)return 0;
    ll res = 0;
    ice[y][x] = 0;
    FOR(i, 0, 4) {
        if (x + dx[i] < 0 || x + dx[i] >= w || y + dy[i] < 0 || y + dy[i] >= h)continue;
        res = max(res, 1 + dfs(y + dy[i], x + dx[i]));
    }
    ice[y][x] = 1;
    return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> w>>h;
  FOR(i, 0, h)FOR(j, 0, w)cin >> ice[i][j];
  FOR(i, 0, h)FOR(j, 0, w) {
      ans = max(ans, dfs(i, j));
  }

  cout << ans << endl;

  return 0;
}
