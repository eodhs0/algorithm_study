#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int chessBoard[300][300]; // ü���� ���� �ִ� 300. �� ������ �̵� �Ÿ� ������ �迭.
bool check[300][300];

/* ����Ʈ�� �̵� �� �� �ִ� ��ǥ */
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int T; // �׽�Ʈ ���̽� �Է�
int lenOfBoard; // ü���� ����
int nowX, nowY; // ����Ʈ ���� ��ġ
int goX, goY; // ����Ʈ�� �����ϴ� ��ġ

int bfs() {
	// Test case�� �������̱� ������ �湮 �迭 / ���� �̵�Ƚ�� �迭 �ʱ�ȭ
	for (int i = 0; i < lenOfBoard; i++) {
		for (int j = 0; j < lenOfBoard; j++) {
			check[i][j] = false;
			chessBoard[i][j] = 0;
		}
	}
	queue<pair<int, int>> q; // BFS �� ���� queue
	q.push(make_pair(nowX, nowY)); // ���� ��ġ push
	while (!q.empty()) {
		if ((nowX == goX && nowY == goY)) // ���� ��ġ�� ��ǥ ��ġ�� �����ϸ� break
			break;
		int x = q.front().first; 
		int y = q.front().second;
		check[x][y] = true;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (nextX == goX && nextY == goY) {
				chessBoard[nextX][nextY] = chessBoard[x][y] + 1;
				nowX = goX;
				nowY = goY;
				//cout << "hi" << endl;
				break;
			}
			if (nextX >= 0 && nextY >= 0 && nextX < lenOfBoard && nextY < lenOfBoard && !check[nextX][nextY]) {
				//cout << chessBoard[x][y] << " " << nextX << " " << nextY << endl;
				q.push(make_pair(nextX, nextY));
				check[nextX][nextY] = true;
				chessBoard[nextX][nextY] = chessBoard[x][y] + 1;
			}
		}
	}
	return chessBoard[nowX][nowY];
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> lenOfBoard >> nowX >> nowY >> goX >> goY;
		cout << bfs() << endl;
	}
}