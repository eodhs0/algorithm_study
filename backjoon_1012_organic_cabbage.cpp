#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, K; // ���߹� ���α���, ���α���, ���� �ɾ����ִ� ����
bool check[50][50]; // ���߹翡�� �湮�� �� check�ϴ� �迭
int farm[50][50]; // ���߽��� �迭

void initialize() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			farm[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

int bfs() {

}

int solve() {

}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int T; cin >> T; // �׽�Ʈ���̽� �Է�

	for (int i = 0; i < T; i++) {
		cin >> M, N, K;
		initialize();
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x, y;
			farm[x][y] = 1;
		}
	}
}