#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/26  Problem: ABC025 C / Link: http://abc025.contest.atcoder.jp/tasks/abc025_c ----- */
/* ------問題------

直大くんと直子さんは双子の兄妹です。時々、休日に 2 人でゲームをしています。

ゲームは○×ゲームをベースにしており、以下の要領でゲームが行われます。

ゲームは縦 3 マス、横 3 マスの盤面を使います。ゲーム開始時点ではどのマスにも文字が書かれていません。
挨拶した後、直大くんから始めて交互に文字を書いていきます。文字は盤面上のまだ文字が書かれていないマスの上にのみ書くことができます。そのようなマスが複数ある場合は好きな 1 箇所を選んで書きます。書く文字は、直大くんが○、直子さんが×です。
合わせて 9 回文字を書いた時点で、すべてのマスが埋まります。その後、得点計算を行い、得点の高い方が勝ちます。
得点計算は以下の方法で行われます。ここで、盤面の左上のマスをマス (1,1) とし、左上から下に i?1(1≦i≦3) マス、右に j?1(1≦j≦3) マス進んだところにあるマスをマス (i,j) と呼ぶことにします。

1≦i≦2 および 1≦j≦3 を満たすすべての整数組 (i,j) に対して、マス (i,j) とマス (i+1,j) に書かれているマスを見て、同じ文字が書かれていたなら直大くんに、違う文字が書かれていたなら直子さんに bi,j 点が入る。
1≦i≦3 および 1≦j≦2 を満たすすべての整数組 (i,j) に対して、マス (i,j) とマス (i,j+1) に書かれているマスを見て、同じ文字が書かれていたなら直大くんに、違う文字が書かれていたなら直子さんに ci,j 点が入る。
直大くんも直子さんも、最終的に得られる自分の得点ができるだけ多くなるようにゲームを行います。両者が最善を尽くしたときのそれぞれの得点を計算してください。

-----問題ここまで----- */
/* -----解説等-----

min-max法。TDPCでやったのでイメージがしやすかった。
片側では最大の値を、もう片側では最小の値をとるようにすれば題意を満たす。

 ----解説ここまで---- */


int b[2][3], c[3][2];
int board[3][3];

int calc(int t) {

    if (t == 9) {
        int sum = 0;
        FOR(i, 0, 2)FOR(j, 0, 3) {
            if (board[i][j] == board[i + 1][j])
                sum += b[i][j];
        }
        FOR(i, 0, 3)FOR(j, 0, 2) {
            if (board[i][j] == board[i][j + 1])
                sum += c[i][j];
        }
        return sum;
    }

    int maxv = -INF, minv = INF;

    FOR(i, 0, 3)FOR(j, 0, 3) {
        if (board[i][j] != -1) continue;

        if (t % 2 == 1)board[i][j] = 0;
        else board[i][j] = 1;

        int num = calc(t + 1);

        maxv = max(maxv, num);
        minv = min(minv, num);
        board[i][j] = -1;
    }

    if (t % 2 == 0) {
        return maxv;
    }
    else {
        return minv;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int sum = 0;

    FOR(i, 0, 2)FOR(j, 0, 3) {
        cin >> b[i][j];
        sum += b[i][j];
    }
    FOR(i, 0, 3)FOR(j, 0, 2) {
        cin >> c[i][j];
        sum += c[i][j];
    }

    memset(board, -1, sizeof(board));

    int ans = calc(0);
    cout << ans << endl;
    cout << sum - ans << endl;

    return 0;
}