//警告	C6386	写入到“num”时缓冲区溢出: 可写大小为“tn*4”个字节，但可能写入了“8”个字节。		24	
//警告	C6385	从“num”中读取的数据无效 : 可读大小为“tn * 4”个字节，但可能读取了“8”个字节。	28

//****帮帮忙，上面的警告到底什么意思啊

/*Josephus问题的数组实现
输入N K M(合理简洁的提示)，输出淘汰顺序。其中：
N为总人数，初始从第K人开始由1到M循环报数，报到
M的人被淘汰。
*/
#include <iostream>
using namespace std;

int main() {
	int M = 0, N = 0, K = 0, remain = 0;

	cout << "请输入总人数N: \t";
	cin >> N;
	cout << "请输入报数M: \t";
	cin >> M;
	cout << "请输入起始位置K: ";
	cin >> K;

	int roller = 0, baoshu = 1;
	int tn = N + 10;
	int* num = new int[tn];
	remain = N;
	for (int i = 0; i <= tn; i++) {
		num[i] = i + 1;
	};
	roller = K - 1;
	while (remain > 1) {
		if (num[roller] != 0) {

			if (baoshu != M) {
				if (roller != N - 1) { roller = roller + 1; }
				else { roller = 0; }
				baoshu = baoshu + 1;

			}
			else {
				cout <<"淘汰：" <<num[roller] << endl;
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

