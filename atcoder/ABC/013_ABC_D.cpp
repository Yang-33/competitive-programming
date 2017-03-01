#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
typedef long long ll;

/* -----  2017/03/01  Problem: ABC013 D / Link: http://abc013.contest.atcoder.jp/tasks/abc013_4 ----- */
/* ------問題------

N本の縦線とM本の横線で構成されたあみだくじがある。
(M本の横線の位置の情報が与えられる。)
このくじをD個縦につなげたとき、
左からi番目(1<=i<=Nを満たすi全て)の縦線を選ぶと
最終的にどこにたどり着くかそれぞれ答えなさい。(長いので要約)

-----問題ここまで----- */
/* -----解説等-----

クエリの高速処理なら014とおんなじやん!?とはなったけど
ダブリングをうまく使いこなせておらず正解ならず。
しかしダブリングであった。遷移するタイプはダブリングで前処理しておけば便利な場合が多いのかも。
2^kのテーブルを作れば遷移がlogで抑えられる。実質増加二分探索。

移動先をもとめるときに、横棒は逆順から適用していかないとダメ
普通の順番で適用すると、「下側のi番目に上側の何番目が入るか」を求めてしまう
求めるべきは「上側のi番目が下側の何番目に入るか」である (1WA)

 ----解説ここまで---- */

ll N, M, D;
ll ans = 0LL;
int c[200010];
ll doub[32][100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> D;
    FOR(i, 0, N) {
        doub[0][i] = i;
    }

    FOR(i, 0, M) {
        cin >> c[i];
    }

    FORR(i, M - 1, -1) {
        swap(doub[0][c[i]], doub[0][c[i] - 1]);
    }//あみだ

    FOR(k, 0, 30) { //2^kテーブル作成
        FOR(v, 0, N) {
            doub[k + 1][v] = doub[k][doub[k][v]];
        }
    }

    FOR(i, 0, N) {
        int d = D;
        int pos = i;
        int k = 0;
        do {
            if (d & 1)pos = doub[k][pos];
            d >>= 1;
            k++;
        } while (d != 0);
        cout << pos + 1 << endl;
    }


    return 0;
}