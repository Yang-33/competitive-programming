#include<iostream>
#include<string>
#define FOR(i,s,t) for(int (i)=(s);(i)<(t);i++)
using namespace std;

/* -----  2017/03/24  Problem: RUPC2017 day3 E / Link: http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day3&pid=E ----- */
/* ------問題------

リンク参照

-----問題ここまで----- */
/* -----解説等-----

f(x)は区間塗りつぶしとsumクエリとして遅延セグ木で処理できる。
g(x)は区間の両端の数字を保持しておけば、右の区間と左の区間の間の数字を見て両方１なら１を足せばよい。
setで区間管理もできるらしいのでそれもやりたい

----解説ここまで---- */

#define MAX_N 300000
int n, q, gn = 1;
string x;
const int NON = -1;
int lazy[MAX_N];
int f[MAX_N];
int g[MAX_N];
int L[MAX_N];
int R[MAX_N];

void init(int n) {
    while (gn < n) {
        gn *= 2;
    }
    FOR(i, 0, gn * 2 - 1) {
        lazy[i] = NON;
        f[i] = 0;
        g[i] = 0;
        L[i] = 0;
        R[i] = 0;
    }
}
inline void lazy_push(int k, int queryL, int queryR) {// <= lazy_evaluate
    if (lazy[k] == NON)return;

    f[k] = lazy[k] * (queryR - queryL);
    g[k] = lazy[k] * (queryR - queryL - 1);
    L[k] = lazy[k];
    R[k] = lazy[k];
    if (k < gn - 1) {
        lazy[2 * k + 1] = lazy[k];
        lazy[2 * k + 2] = lazy[k];
    }
    // 子に命令を伝搬させたので、命令を空にする
    lazy[k] = NON;
}

inline void fix(int  k) {
    // ノードkに対応する　値に修正
    //dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);//min/max
    f[k] = f[k * 2 + 1] + f[k * 2 + 2];//sum
    g[k] = g[k * 2 + 1] + g[k * 2 + 2] + R[k * 2 + 1] * L[k * 2 + 2];
    L[k] = L[k * 2 + 1];
    R[k] = R[k * 2 + 2];

}

inline void set_lazy(int k, int val) {
    lazy[k] = val;
}

inline void rangefill(int a, int b, int num, int k = 0, int l = 0, int r = gn) {
    lazy_push(k, l, r);

    if (r <= a || b <= l) return;

    if (a <= l && r <= b) {
        set_lazy(k, num);
        lazy_push(k, l, r);
        return;
    }
    else {
        rangefill(a, b, num, k * 2 + 1, l, (l + r) / 2);
        rangefill(a, b, num, k * 2 + 2, (l + r) / 2, r);

        fix(k);
        return;
    }
}



int main() {

    cin >> n >> x >> q;
    // update
    init(n);
    FOR(i, 0, x.size()) {
        rangefill(i, i + 1, x[i] - '0', 0, 0, gn);
    }

    FOR(i, 0, q) {
        int l, r, b;
        cin >> l >> r >> b;
        // query    
        rangefill(l - 1, r, b, 0, 0, gn);
        lazy_push(l, 0, gn);
        cout << f[0] - g[0] << endl;
    }
    return 0;
}
