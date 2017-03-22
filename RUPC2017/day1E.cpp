#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i, s, t) for (int i = s; i < t; i++)

/* -----  xtimex  Problem: RUPC2017 E / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=E
 */
/* ------問題------

リンク参照

-----問題ここまで----- */
/* -----解説等-----

当初はdpっぽいですねとオムさんと話しており、逆順から見た方がよさそう？などと考えていた
僕が状態の持ち方がdp[現在みている文字][何回折り返したか]ではよくわからないと言ったら後ろに反転の方向を上下で[2][2]で持てばいいのでは？
とのアドバイスをいただき実装。テンパって遷移がわからなくなったり怪しいものを書いてしまったりＫに関するループがKまで回し切らないといけなかったり
0~Kまで解は異なることに気付かず何度も助けてもらった。
途中パソコンがダウンしたりした後、コンテスト終了二分後にＡＣ。
悔しい；；　が様々な知見を得たので勉強になった。
memsetでは通らないことを本当に理解したので使用せず丁寧に初期化をするべき。
最適なコードは帰ったら書く
dp[今見ている文字][何回ひっくり返したか][上下に反転しているか][左右に反転しているか]
:= 現在の設定の最大値。
これをdp[S][0-K+1][0-2][0-2]で最大値をとればよい。

----解説ここまで---- */

int dp[2010][2010][2][2];

int main() {
  string S;
  int K;
  cin >> S >> K;
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;

            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  int ans = 0;
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  // cout << "ans? " << ans << endl;
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  // int ans = 0;
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {

    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  cout << ans << endl;
  return 0;
}