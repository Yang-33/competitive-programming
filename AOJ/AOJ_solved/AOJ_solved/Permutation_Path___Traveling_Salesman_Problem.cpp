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
#define MOD 1000000007
#define llong long long
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
llong N;

/* 2017/01/11 ��� DPL_2_A  Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A ----- */
/* -----�����-----
���: ����Z�[���X�}�����
�d�ݕt���L���O���t G(V,E) �ɂ��āA�ȉ��̏����𖞂����ŒZ�o�H�̋��������߂ĉ������F

���钸�_����o�����A�o���_�֖߂�H�ł���B
�e���_�����傤�ǂP�x�ʂ�B

|V|, |E| �͂��ꂼ��O���t G �̒��_�̐��ƕӂ̐��������B
�O���t G �̒��_�ɂ͂��ꂼ�� 0, 1, ..., |V|-1 �̔ԍ����t�����Ă���B

s_i, t_i �̓O���t G �� i �Ԗڂ̕ӂ����ԂQ�̒��_��\���i�L���j�B
d_i �� s_i �� t_i �̊Ԃ̋����@�ii �Ԗڂ̕ӂ̏d�݁j�ł���B


�ŒZ�o�H�̋�����1�s�ɏo�͂���B�����𖞂����o�H���Ȃ��ꍇ�� -1 �Əo�͂���B

����
2 ? |V| ? 15
0 ? d_i ? 1,000
G �ɑ��d�ӂ͂Ȃ�


---------------------------------------------------






*/
ll V, E;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N;

    cout << N << endl;

    return 0;
}