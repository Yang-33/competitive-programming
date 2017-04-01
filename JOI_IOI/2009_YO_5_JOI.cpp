#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/31  Problem: JOI予選 2009 5  / Link: https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t5/2009-yo-t5.html  ----- */
/* ------問題------

1 から n までの番号が書かれた n 枚のカードがある． まず，一番上が番号 1 のカード，上から2枚目が番号 2 のカード，…，一番下が番号 n のカードとなるように順番に重ねて，カードの山を作る．

カードの山に対して， 「シャッフル(x,y)」と呼ばれる次のような操作を行うことで， カードを並び替える（x, y は 1 ≦ x ＜ y ＜ n をみたす整数）．
シャッフル(x,y)
n 枚のカードを， 一番上から x 枚目までのカードからなる山A， x+1 枚目から y 枚目のカードからなる山B， y+1 枚目から n 枚目のカードからなる山C の3つの山に分ける．
そして，山Aの上に山Bを重ね，さらにその上に山Cを重ねる．

例えば， 順番に並んでいる9枚のカードに対して「シャッフル(3,5)」を行うと， 9 枚のカードに書かれた番号は, 上から順番に 6, 7, 8, 9, 4, 5, 1, 2, 3 となる．
最初の山の状態から m 回のシャッフル「シャッフル(x1, y1)」「シャッフル(x2, y2)」 … 「シャッフル(xm, ym)」を順番に行った後のカードの山において，
上から数えて p 枚目から q 枚目のカードの中に番号が r 以下のカードが何枚含まれているかを求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

愚直なカードの入れ替えでは間に合わないので、区間の管理を集合で行うことにする。閉区間で管理した。
一枚だけの集合は[5,5]みたいになる。
集合管理をしっかりできるようにしたい。
めっちゃ実装面倒かと思ったけどそうでもなかった。

----解説ここまで---- */


int N, M;
int p, q, r;
int x[5001], y[5001];

ll solve() {
    vector<pii>L;
    L.push_back(pii(1, N));
    x[M] = p - 1, y[M] = q;
    FOR(i, 0, M + 1) {
        vector<pii>a, b;
        int sum = 0;
        int pos;
        FOR(j, 0, L.size()) {
            pii d = L[j];
            if (x[i] == 0)break;
            if (sum + (d.second - d.first + 1) <= x[i]) {
                a.push_back(d);
                sum += (d.second - d.first + 1);
                pos = j + 1;
                if (sum == x[i])break;
            }
            else {
                a.push_back(pii(d.first, x[i] + d.first - 1 - sum));
                L[j] = pii(x[i] + d.first - sum, d.second);
                pos = j;
                break;
            }
        }
        sum = x[i];
        FOR(j, pos, L.size()) {
            pii d = L[j];
            if (x[i] == y[i])break;
            if (sum + (d.second - d.first + 1) <= y[i]) {
                b.push_back(d);
                sum += (d.second - d.first + 1);
                pos = j + 1;
                if (sum == y[i])break;
            }
            else {
                b.push_back(pii(d.first, y[i] + d.first - 1 - sum));
                L[j] = pii(y[i] - sum + d.first, d.second);
                pos = j;
                break;
            }
        }
        L.erase(L.begin(), L.begin() + pos);
        if (i == M) {
            L = b;
            break;
        }
        L.insert(L.end(), b.begin(), b.end());
        L.insert(L.end(), a.begin(), a.end());
    }
    ll res = 0;
    for (auto it = L.begin(); it != L.end(); it++) {
        int l = (*it).first, u = (*it).second;
        if (l > r)continue;
        if (u <= r)res += u - l + 1;
        else {
            res += r - l + 1;
        }
    }
    return res;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N;
    cin >> M;
    cin >> p >> q >> r;
    FOR(i, 0, M)
        cin >> x[i] >> y[i];
    cout << solve() << endl;
    return 0;
}
