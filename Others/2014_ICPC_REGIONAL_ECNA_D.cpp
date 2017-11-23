#include  <bits/stdc++.h>
using namespace std;


/* -----  2017/11/23  Problem:   
2014-2015 ACM-ICPC East Central North America Regional Contest (ECNA 2014) D / Link: http://codeforces.com/gym/100641  ----- */
/* ------���------

���[�}�����񂪗^������B
�ׂ荇����������������Ƃ��A�召���������Ȃ��Ȃ�΍��̐�Βl���Ƃ�B
���ꂤ�鐔�������ׂďo�͂���B

-----��肱���܂�----- */
/* -----�����-----

���������O(N^3)�����Avector�ł���MLE�ɂȂ�����TLE�ɂȂ����肷��B
���N���N�R���e�X�g���B
���O�̍\���̂������Ă����Ηǂ��B�i�ǂ��Ȃ����j

----��������܂�---- */


int romeEval(const int a, const int b) {
	if (a < b) {
		return b - a;
	}
	else {
		return b + a;
	}
}

int evalChar(const char c) {
	switch (c) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	}
	assert(false);
	return -1;
}

const int NUM_VAL = 5001;

struct arr {
	int size;
	int vals[NUM_VAL];
};

// segLen, start
arr dp[51][50];

void push(const int val, arr &a) {
	a.vals[a.size] = val;
	a.size++;
}

void init(arr &a) {
	memset(a.vals, -1, NUM_VAL);
	a.size = 0;
}

// visited set
bool bs[NUM_VAL];

void merge_subseq(const int segLen, const int start) {
	// k is the splitting point for recursion
	for (int k = 1; k < segLen; k++) {
		int s1 = dp[k][start].size;
		int s2 = dp[segLen - k][start + k].size;

		for (int i = 0; i < s1; i++) {
			for (int j = 0; j < s2; j++) {
				int res = romeEval(dp[k][start].vals[i], dp[segLen - k][start + k].vals[j]);
				if (!bs[res]) {
					push(res, dp[segLen][start]);
					bs[res] = true;
				}
			}
		}
	}
}


int main() {
	for (int t = 1; ; t++) {
		string seq;
		cin >> seq;
		if (seq == "0") break;
		int n = seq.size();

		// evaluate single characters
		for (int start = 0; start < n; start++) {
			int res = evalChar(seq[start]);
			init(dp[1][start]);
			push(res, dp[1][start]);
		}

		// max 49 of these
		for (int segLen = 2; segLen <= n; segLen++) {

			// max 49 of these
			for (int start = 0; start <= n - segLen; start++) {
				init(dp[segLen][start]);

				// clear visited set after every segment size
				for (int i = 0; i < NUM_VAL; i++)bs[i] = 0;// (bs, NUM_VAL);
				merge_subseq(segLen, start);
			}
		}

		// get final values into vector
		vector<int> fv;
		for (int i = 0; i < dp[n][0].size; i++) {
			fv.push_back(dp[n][0].vals[i]);
		}

		sort(fv.begin(), fv.end());

		cout << "Case " << t << ":";
		for (int i = 0; i < fv.size(); i++) {
			cout << " " << fv[i];
		}
		cout << endl;
	}

	return 0;
}