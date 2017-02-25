#include<iostream>
#include<vector>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* -----  2017/02/26  Problem: ABC025 D / Link: http://abc025.contest.atcoder.jp/tasks/abc025_d ----- */
/* ------問題------
高橋君は縦 5 マス、横 5 マスの盤面に 1 から 25 までの整数を 1 つずつ書き込もうとしています。

高橋君は以下の条件をすべて満たすように整数を配置しようと考えています。

整数は各マスに 1 つずつ割り当てる。
縦または横に連続する 3 つの整数をどのように取り出しても、それらは昇順または降順になっていない。すなわち、上から i(1≦i≦5) 番目、左から j(1≦j≦5) 番目のマスに書かれた整数を ni,j としたとき、以下の 2 条件が成立する。
ni,j<ni+1,j<ni+2,j あるいは ni,j>ni+1,j>ni+2,j を満たす整数組 (i,j)(1≦i≦3,1≦j≦5) が存在しない。
ni,j<ni,j+1<ni,j+2 あるいは ni,j>ni,j+1>ni,j+2 を満たす整数組 (i,j)(1≦i≦5,1≦j≦3) が存在しない。
すでにいくつかのマスについては、どの整数を書き込むかは決まっています。あなたの課題は、上記の条件を満たすような残りの整数の配置の総数を計算することです。

-----問題ここまで----- */
/* -----解説等-----

どうしてもN!解法にしかならずずっと考えていた。
1から埋めていこうとすればいいという発想になるまでかなり時間がかかってしまった。
１から埋めていこうとすることで大小関係の考慮の仕方が非常に簡単になる。唯一片側が埋まっている状態のときに
単調減少または単調増加になってしまうのでカウントをしなければよい。
順序付けができてしまえば確認したかどうかのみが重要であり、これはbitDPで簡単に状態を管理することができる。
発想に至るまでがむずかしい。まだまだだ。。。

 ----解説ここまで---- */

ll N;
int dp[1 << 25];
vector<int> v;
int masu[26];

ll ans = 0LL;

int countbit(int n) {
    int ret = 0;
    while (n) {
        n &= n - 1;
        ++ret;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    memset(masu, -1, sizeof(masu));

    FOR(i, 0, 25) {
        int a; cin >> a;
        if (a == 0) {
            v.push_back(i);
        }
        else {
            masu[a] = i;
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    FOR(i, 0, (1 << 25) - 1) {
        if (dp[i]) {
            int c = countbit(i) + 1;
            int r = masu[c];

            if (r != -1) {
                int y = r / 5, x = r % 5;
                if ((i&(1 << r)) == 0) {
                    if (y > 0 && y < 4 && ((i >> (r - 5)) ^ (i >> (r + 5))) & 1) continue;
                    if (x > 0 && x < 4 && ((i >> (r - 1)) ^ (i >> (r + 1))) & 1) continue;

                    dp[i | (1 << r)] = (dp[i | (1 << r)] + dp[i]) % MOD;
                }
            }
            else {
                FOR(s, 0, v.size()) {
                    int j = v[s];
                    int y = j / 5, x = j % 5;
                    if ((i&(1 << j)) == 0) {
                        if (y > 0 && y < 4 && ((i >> (j - 5)) ^ (i >> (j + 5))) & 1) continue;
                        if (x > 0 && x < 4 && ((i >> (j - 1)) ^ (i >> (j + 1))) & 1) continue;

                        dp[i | (1 << j)] = (dp[i | (1 << j)] + dp[i]) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[(1 << 25) - 1] << endl;

    return 0;
}