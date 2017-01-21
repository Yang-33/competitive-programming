#include<iostream>
#include<map>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 ��� ----- ABC045 D /Link http://abc045.contest.atcoder.jp/tasks/arc061_b */
/* -----�����-----
���: �c H �s�A�� W ��̃}�X�ڂ���Ȃ�Ղ�����܂��B�ŏ��A�ǂ̃}�X�ڂ������h���Ă��܂��B
���ʂ��N���A���̂��� N �}�X�������h��Ԃ��܂����Bi ��� ( 1��i��N ) �ɓh��Ԃ����̂́A �ォ�� ai �s�ڂō����� bi ��ڂ̃}�X�ł����B
���ʂ��N���}�X�ڂ�h��Ԃ�����̔Ղ̏�Ԃɂ��āA�ȉ��̂��̂̌����v�Z���Ă��������B
�e���� j ( 0��j��9 ) �ɂ��āA�Ղ̒��Ɋ��S�Ɋ܂܂�邷�ׂĂ� 3 �s 3 ��̘A������}�X�ڂ̂����A�����}�X�����傤�� j ������́B

����
3��H��109
3��W��109
0��N��min(105,H�~W)
1��ai��H (1��i��N)
1��bi��W (1��i��N)
(ai,bi)��(aj,bj) (i��j)

�e�}�X���J�E���g���ʂɉe�����y�ڂ��͍̂ő�X�}�X�A�������̑ΏۂɂȂ�̂� 2 ~ W-1 and 2 ~ H-1
map�Ő����グ����Ίy�B
map�̒l�̂ق����L�[�Ƃ���ans�𑝂₷

*/

ll H, W, N;
map<pair<int, int>, int>mp;
ll left0;
ll ans[10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W >> N; //y,x

    int a, b; //1 -> H or W

    FOR(i, 0, N) {
        cin >> b >> a;
        FOR(x, -1, 2)FOR(y, -1, 2) {
            if (a + x >= 2 && a + x <= W - 1 && b + y >= 2 && b + y <= H - 1)
                mp[make_pair(a + x, b + y)]++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans[it->second]++;
    }

    left0 = (H - 2)*(W - 2)-mp.size();

    cout << left0 << endl;

    FOR(i, 1, 10)
        cout << ans[i] << endl;

    return 0;
}