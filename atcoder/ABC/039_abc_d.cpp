#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/27 問題 ----- ABC039 D/Link http://abc039.contest.atcoder.jp/tasks/abc039_d */
/* -----解説等-----
問題: 2 値画像に対して行う、収縮という処理があります。
なお、2 値画像とは、画素の色が白か黒かの 2 種類しかない画像の事です。
収縮とは、それぞれの画素についてその画素と周り 8 方向の画素のうち、一つでも黒い画素があったらその画素を黒くするという処理です。
ここで、画素数が高さ H、幅 W の 2 値画像を考えます。
この画像はある画像に一回収縮を行ったものであることがわかっています。
元の画像として考えられるものがあるかを判定し、もしあるならばそのうちどれか 1 つを復元してください。
画像は、H 個の、W 文字の文字列 Si で与えられます。Si の j 文字目は
、上から i 個目、左から j 個目の画素の色を表しており、. なら白、# なら黒です。

白色のマスが存在すればその周りのマスに黒いマスはない。
それによって復元したマスに対して色塗りをもう一度行い、これが元のマスと一致すれば復元可能、一致しなければ復元不可能となる。

*/

int N, M;
char f[105][105];

int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

bool u[105][105];
char G[105][105];
char F[105][105];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    FOR(i, 0, N)FOR(j, 0, M)cin >> f[i][j];

    FOR(i, 0, N)FOR(j, 0, M) {
        if (f[i][j] == '.') {
            u[i][j] = 1;
            FOR(k, 0, 8) {
                int nx = i + dx[k], ny = j + dy[k];
                if (0 <= nx&&nx < N && 0 <= ny&&ny < M) {
                    u[nx][ny] = 1;
                }
            }
        }
    }

    FOR(i, 0, N)FOR(j, 0, M) {
        if (u[i][j]) F[i][j] = '.'; 
        else F[i][j] = '#';
    }

    FOR(i, 0, N)FOR(j, 0, M) {
        G[i][j] = F[i][j];
        for (int k = 0; k < 8; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (0 <= nx&&nx < N && 0 <= ny&&ny < M&&F[nx][ny] == '#') {
                G[i][j] = '#';
            }
        }
    }
    FOR(i, 0, N)FOR(j, 0, M) {
        if (G[i][j] != f[i][j]) {
            cout << "impossible" << endl; 
            return 0;
        }
    }

    cout << "possible" << endl;

    FOR(i, 0, N)FOR(j, 0, M) {
        cout << F[i][j];
        if (j == M - 1)cout << endl;
    }

    return 0;
}