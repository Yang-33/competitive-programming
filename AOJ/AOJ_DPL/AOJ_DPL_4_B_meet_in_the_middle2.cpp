#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2010/00/00 ��� -----  Name/Link ----- */
/* -----�����-----
���: �R�C���̑g�ݍ��킹 II
N ���̃R�C��������܂��B���ꂼ��̃R�C���̒l�i��ai �~�ł��B
E �N��, ���傤��K �̃R�C���𓾂����Ǝv���Ă���,
�l�i�̍��v��L �~�ȏ� R �~�ȉ��ɂ������Ǝv���Ă��܂��B
���̂悤�ȃR�C���̑I�ѕ��͉��ʂ肠��ł��傤��?
������, ���ꂼ��̃R�C���͋�ʂ�����̂Ƃ��܂��B

�����S�񋓂�p���邪�A�l�̕����ł͉����Ԃɔ͈͂���������悤�ɂ��邱�Ƃ͗e�Ղł���B
����ŃR�C���̖������m���ȉ��̂����̂j�����g���悤�ɂ��Ȃ���΂Ȃ炸�A
part_n1 + part_n2 = K ���݂����悤�Ȃ��̂�{�����Ă����΂悢�B

�O�������ł͎g�p�����ƂɃR�C���̉��l���L�^���A�����Ƀ\�[�g����B
�㔼�����ł� K - part_n2 ���L�[�Ƃ��� L �~�ȏ� R �~�ȉ��ƂȂ�悤�ɒl�����߂�΂悢�B

*/
#define MAX_N 40
ll N, K, L, R;
ll a[MAX_N];
vector<ll> rec[MAX_N / 2 + 1];
ll ans = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K >> L >> R;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    int n1 = N / 2;
    FOR(i, 0, (1 << n1)) {
        int cnt1 = 0;
        ll s = 0;
        FOR(j, 0, n1) {
            if ((i >> j) & 1) {
                cnt1++;
                s += a[j];
            }
        }
        rec[cnt1].push_back(s);
    }

    FOR(i, 0, n1) {
        sort(rec[i].begin(), rec[i].end());
    }

    int n2 = N - n1;
    FOR(i, 0, (1 << n2)) {
        int cnt2 = 0;
        ll s = 0;
        FOR(j, 0, n2) {
            if ((i >> j) & 1) {
                cnt2++;
                s += a[n1 + j];
            }
        }

        //n1+cnt2=K�ł��肽���A�����ēY�����͂O�ȏ�ł��肽��
        if ((!(K - cnt2 >= 0)) || n1 + cnt2 < K)continue;
        // R-s�~���傫���ʒu���ł�̂�-1
        int UP = upper_bound(rec[K - cnt2].begin(), rec[K - cnt2].end(), R - s) - begin(rec[K - cnt2]) - 1;
        int LW = lower_bound(rec[K - cnt2].begin(), rec[K - cnt2].end(), L - s) - begin(rec[K - cnt2]);
    
        if (UP - LW < 0)continue;
        ans += UP - LW + 1;
    
    }

    cout << ans << endl;

    return 0;
}
