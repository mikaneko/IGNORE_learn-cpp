
/*Josephus问题的数组实现
输入N K M(合理简洁的提示)，输出淘汰顺序。其中：
N为总人数，初始从第K人开始由1到M循环报数，报到
M的人被淘汰。
*/
#include <iostream>
using namespace std;

int main() {
	int M = 0, N = 0, K = 0, remain = 0;

	cout << "请输入总人数N(<=100): \t";
	cin >> N;
	cout << "请输入报数M: \t";
	cin >> M;
	cout << "请输入起始位置K: ";
	cin >> K;

	int roller = 0, baoshu = 1;
	int num[110] = { 0 };
	remain = N;
	for (int i = 0; i <= 109; i++) {
		num[i] = i + 1;
	}
	roller = K - 1;
	while (remain > 1) {
		if (num[roller] != 0) {

			if (baoshu != M) {
				if (roller != N - 1) { roller = roller + 1; }
				else { roller = 0; }
				baoshu = baoshu + 1;

			}
			else {
				cout << "淘汰：" << num[roller] << endl;
				baoshu = 1;
				num[roller] = 0;
				remain = remain - 1;
			}

		}
		else if (roller != N - 1) { roller = roller + 1; }
		else { roller = 0; }

	}

	return 0;
}

