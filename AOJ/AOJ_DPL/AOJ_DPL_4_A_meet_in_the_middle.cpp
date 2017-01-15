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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
ll N;

/* 2017/01/16 ��� AOJ_DPL_4_A  Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_4_A */
/* -----�����-----
���:�R�C���̑g�ݍ��킹
�S�̑܂`, �a, �b, �c�ɂ��ꂼ�� N ��, ���v 4N ���̃R�C���������Ă��܂��B
���ꂼ��̑܂ɓ����Ă���R�C���̒l�i��ai, bi, ci, di �~�ł��B
D�N��,�e�܂���1��,���v4���̃R�C���𓾂����Ǝv���Ă���,�l�i�̍��v�͂��傤��V�~�ɂ������Ǝv���Ă��܂��B
���̂悤�ȃR�C���̑I�ѕ��͉��ʂ肠��ł��傤��? 
������, ���ꂼ��̃R�C���͋�ʂ�����̂Ƃ��܂��B

�I�ѕ��̑����� 1 �s�ɏo�͂��Ȃ����B

�������g�ݍ��킹�� n^4 = 1000^4 =10^12 (Over)
�����S�񋓂��s���Ύ��Ԍv�Z�ʂ͂n(n^2 log n) =10^6 log n �ƂȂ�n�j�I
a,b�̑g�ݍ��킹��S�񋓂��A�\�[�g����B
�����c,d�̑g�ݍ��킹�� V-c-d=a+b�ƂȂ�悤�Ȃ��̂𔭌�����΂悢�B
�����̓\�[�g�ςݔz���p���Ă���̂ł��邩��lower_bound/upper_bound��p����log�ƂȂ�B


*/
#define MAX_N 1000
ll V;
ll a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];
ll record[MAX_N*MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N>>V;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N) {
        cin >> b[i];
    }
    FOR(i, 0, N) {
        cin >> c[i];
    }
    FOR(i, 0, N) {
        cin >> d[i];
    }

    FOR(i, 0, N) {
        FOR(j, 0, N) {
            record[i*N + j] = a[i] + b[j];
        }
    }
    sort(record, record + N*N);
    ll ans = 0;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            ll part = V - (c[i] + d[j]);
            ans += upper_bound(record, record + N*N, part) - lower_bound(record, record + N*N, part);
        } //part ���̂��̂̒l
    }


    cout << ans << endl;

    return 0;
}