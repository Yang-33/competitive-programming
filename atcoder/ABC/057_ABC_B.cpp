#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/27  Problem: ABC 057 B / Link: http://abc057.contest.atcoder.jp/tasks/abc057_b ----- */
/* ------蝠城｡----

xy 平面があり、その上に N 人の学生がいて、M 個のチェックポイントがあります。
i 番目の学生がいる座標は (ai,bi)(1≦i≦N) であり、番号 j のチェックポイントの座標は (cj,dj)(1≦j≦M) です。
これから合図があり、各学生はマンハッタン距離で一番近いチェックポイントに集合しなければなりません。
2つの地点 (x1,y1) と (x2,y2) 間のマンハッタン距離は |x1−x2|+|y1−y2| で表されます。
ここで、|x| は x の絶対値を表します。
ただし、一番近いチェックポイントが複数ある場合には、番号が最も小さいチェックポイントに移動することとします。
合図の後に、各学生がどのチェックポイントに移動するかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

計算が間に合うので全探索をする。

----解説ここまで---- */
//
ll N, M;
ll a[60], b[60], c[60], d[60];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    
    FOR(i, 0, N) {
        cin >> a[i] >> b[i];
    }
    FOR(i, 0, M) {
        cin >> c[i] >> d[i];
    }

    FOR(i, 0, N) {
        ll m = 1e18; int id;
        FOR(j, 0, M) {
            ll x = abs(a[i] - c[j]) + abs(b[i] - d[j]);
            if (x < m) {
                m= x;
                id = j;
            }
        }
        cout << id+1 << endl;

    }

    return 0;
    }
