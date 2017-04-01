#include <iostream>
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
/* -----  2017/03/31  Problem: JOI予選 2009 1  / Link:  https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t1/2009-yo-t1.html ----- */
/* ------問題------

JOI商事では社員の在社時間をタイムカードで管理している． 社員は，出社すると専用の装置を使ってタイムカードに出社時刻を刻印する． 勤務を終え退社するときにも，タイムカードに退社時刻を刻印する． 時刻は24時間制で扱われる．

防犯上の理由から，社員の出社時刻は7時以降である． また，全ての社員は23時より前に退社する． 社員の退社時刻は常に出社時刻より後である．

入力としてJOI商事の3人の社員Aさん，Bさん，Cさんの出社時刻と退社時刻が与えられたとき， それぞれの社員の在社時間を計算するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

そのままやるとマイナスになるのでそこに注意。
制約からmmが負になることはないが、常に+24 )%24しておけばよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int h[3][2], m[3][2], s[3][2];
    FOR(i, 0, 3) {
        FOR(j, 0, 2)
            cin >> h[i][j] >> m[i][j] >> s[i][j];
    }

    FOR(i, 0, 3) {
        int ss = s[i][1] - s[i][0];
        int mm = m[i][1] - m[i][0];
        int hh = h[i][1] - h[i][0];
        if (ss < 0)ss += 60, mm--;
        if (mm < 0)mm += 60, hh--;

        cout << hh << " " << mm << " " << ss << endl;
    }


    return 0;
}
