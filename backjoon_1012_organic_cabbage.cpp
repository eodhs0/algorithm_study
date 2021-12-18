#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, N, K; // 배추밭 가로길이, 세로길이, 배추 심어져있는 개수
bool check[50][50]; // 배추밭에서 방문한 곳 check하는 배열
int farm[50][50]; // 배추심을 배열

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
	int T; cin >> T; // 테스트케이스 입력

	for (int i = 0; i < T; i++) {
		cin >> M, N, K;
		initialize();
		for (int i = 0; i < K; i++) {
			int x, y; cin >> x, y;
			farm[x][y] = 1;
		}
	}
}