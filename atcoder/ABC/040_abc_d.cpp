#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/27 ��� ----- ABC040 D /Link http://abc040.contest.atcoder.jp/tasks/abc040_d */
/* -----�����-----
���: ���鍑�ɂ� N �̓s�s������A���ꂼ�� 1 ���� N �܂ł̔ԍ��������Ă��܂��B
�����̓s�s�Ԃ����� M �{�̓��H������Ai �{�ڂ̓��H�͓s�s ai �Ɠs�s bi �����Ԃ��̂ŁAyi �N�ɑ���ꂽ���̂ł��B
���̍��̍����͂ƂĂ��S�z���Ȃ̂ŁA���܂�ɌÂ����͎��̂̊댯���������ƍl���Ďg��Ȃ����Ƃ�����܂��B
�����ł��Ȃ��́A���̍��̌�ʏ󋵂𒲍����邱�Ƃɂ��܂����B

Q �l�̍����̏�񂪗^�����܂��Bj �l�ڂ̍����ɂ��āA�s�s vj �ɏZ��ł���A
����ꂽ�N�� wj �N�ȑO (wj �N���傤�ǂ��܂�) �ł���悤�ȓ��H���g��Ȃ����Ƃ��킩���Ă��܂��B
���ꂼ��̍����ɑ΂��A���̐l���Z��ł���s�s���瓹�H�݂̂��g���čs�����ł���悤�ȓs�s�̌������߂Ă��������B


���n�񏇂Ƀ\�[�g���邢�͕��ёւ���UF.
�V���������珇�Ԃɂ��ĂĂ����A�l�̏o����]��size�Ƃ��ċ��߂Ă����΂悢�B
�����UF�͏W���̑傫�����}�C�i�X�ŕۊǂ��A������������邱�ƂŏW���̑傫����m�邱�Ƃ��ł���B
�}�C�i�X�ɂ��邱�Ƃň�̔z��Ő��̒l�ł͍��ԍ��A���̒l�ł͏W���̑傫����\�����Ƃ��ł���d�l�B

*/

#define MAX_V 100010
int pir[MAX_V];//�e�A���邢�͏W���̔ԍ�

void init(int n) {
    FOR(i, 0, n) {
        pir[i] = -1;
    }
}

int root(int x) {
    if (pir[x] < 0) {
        return x;
    }
    else {
        return pir[x] = root(pir[x]);
    }
}

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
        if (pir[y] < pir[x]) swap(x, y);
        pir[x] += pir[y];
        pir[y] = x;
    }
}

bool same(int x, int y) {
    return root(x) == root(y);
}

int size(int x) {
    return -pir[root(x)];
}

//
//int sizes[MAX_V];//�[��
//
//void init(int n) {
//    FOR(i, 0, n) {
//        par[i] = i;
//        sizes[i] = 1;
//    }
//}
///* x�̍���Ԃ����邢�͏W�� */
//int find(int x) {
//    if (par[x] == x) {
//        return x;
//    }
//    else {
//        return par[x] = find(par[x]);
//    }
//}
///* �W��x,y�𕹍�����B */
//void unite(int x, int y) {
//    x = find(x);
//    y = find(y);
//    if (x == y)return;
//    if (sizes[x] > sizes[y])swap(x, y);
//
//    par[y] = x;
//    sizes[x] += sizes[y];
//    //sizes[y] = 0;
//}
//
////�����W�����̔���
//bool same(int x, int y) {
//    return find(x) == find(y);
//}
///* ��x�����ɂ���O���t�̑傫�� */
//int size(int x) {
//    return sizes[find(x)];
//}

#define MAX_M 200001
#define MAX_Q 100000
int N, M;
int a[MAX_M], b[MAX_M], y[MAX_M];
int Q;
int v[MAX_V], w[MAX_V];
vector<vector<pair<int, int>>> edge(MAX_M);
vector<vector<pair<int, int>>> query(MAX_M);
int ans[MAX_Q];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> M;
    init(N);

    FOR(i, 0, M) {
        cin >> a[i] >> b[i] >> y[i];
        a[i]--; b[i]--;
        edge[y[i]].push_back(make_pair(a[i], b[i]));
    }

    cin >> Q;
    FOR(i, 0, Q) {
        cin >> v[i] >> w[i];
        v[i]--;
        query[w[i]].push_back(make_pair(v[i], i));
    }

    FORR(i, MAX_M - 1, -1) {
        FOR(j, 0, query[i].size()) {
            ans[query[i][j].second] = size(query[i][j].first);
        }
        FOR(k, 0, edge[i].size()) {
            unite(edge[i][k].first, edge[i][k].second);
        }
    }

    FOR(i, 0, Q) {
        cout << ans[i] << endl;
    }

    return 0;
}