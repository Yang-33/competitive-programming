#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
typedef long long ll;

/* 2017/01/26 問題 ----- ABC041 C Name/Link https://abc041.contest.atcoder.jp/tasks/abc041_c */
/* -----解説等-----
問題: 高橋学級には N 人の生徒がいます。 生徒は 1 から N まで出席番号が振られています。
i 番目の生徒の身長は ai です。 ai はすべて相異なります。
高橋先生は N 人の生徒を背の高い方から順に並べました。 N 人の生徒の出席番号を背の高い方から順に出力してください。

ソート前にその値にリンクした添え字を復元ができるようにペア―で保存しておけばよい。
FORRで落ちかけた。

*/

int N;
vector<pair<int,int>> a;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    FOR(i, 0, N) {
        int x; cin >> x;
        a.push_back(make_pair(x,i+1));
    }
    sort(a.begin(), a.end());
    

    FORR(i, N-1, -1) {
        cout << a[i].second << endl;
    }

    return 0;
}