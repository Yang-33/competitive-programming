#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/31  Problem: JOI予選 2008 4  / Link: http://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t4/2008-yo-t4.html  ----- */
/* ------問題------

あなたは星空の写真の中から星座を探している．写真には必ず，探したい星座と同じ形・向き・大きさの図形がちょうど一つ含まれている．
ただし，写真の中には星座を構成する星以外に余分な星が写っている可能性がある．

例えば，図 1 の星座は図 2 の写真に含まれている（丸で囲んで示した）．与えられた星座の星の座標を x 方向に 2， y 方向に －3 だけ平行移動すると写真の中の位置になる．

探したい星座の形と写真に写っている星の位置が与えられたとき，星座の座標を写真の中の座標に変換するために平行移動するべき量を答えるプログラムを書け．

-----問題ここまで----- */
/* -----解説等-----

まずx[0],y[0]がどこに移動したかを設定し、その平行移動距離に対して (元の星座)＋(移動量)=(星)が成り立っていればよく、
愚直に行って M*N*M,　探索を線形ではなく二分探索で行えばM*N*logN となる。どっちでもまにあう。
JOI,set大活躍。

----解説ここまで---- */

ll M, N;

ll ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int x[200], y[200];
    cin >> M;
    FOR(i, 0, M)cin >> x[i] >> y[i];
    cin >> N;
    set<pii>s;
    FOR(i, 0, N) {
        int a, b; cin >> a >> b;
        s.insert(pii(a, b));
    }

    for (pii ss : s) {
        bool flag = true;
        FOR(j, 1, M) {
            if (!s.count(pii(ss.first + x[j] - x[0], ss.second + y[j] - y[0]))) {
                flag = false;
                break;
            }
        }
        if (flag)cout << ss.first - x[0] << " " << ss.second - y[0] << endl;

    }


    return 0;
}
