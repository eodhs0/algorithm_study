#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int chessBoard[300][300]; // 체스판 정의 최대 300. 각 셀별로 이동 거리 저장할 배열.
bool check[300][300];

/* 나이트가 이동 할 수 있는 좌표 */
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };

int T; // 테스트 케이스 입력
int lenOfBoard; // 체스판 길이
int nowX, nowY; // 나이트 현재 위치
int goX, goY; // 나이트가 가야하는 위치

int bfs() {
	// Test case가 여러개이기 때문에 방문 배열 / 셀별 이동횟수 배열 초기화
	for (int i = 0; i < lenOfBoard; i++) {
		for (int j = 0; j < lenOfBoard; j++) {
			check[i][j] = false;
			chessBoard[i][j] = 0;
		}
	}
	queue<pair<int, int>> q; // BFS 를 위한 queue
	q.push(make_pair(nowX, nowY)); // 시작 위치 push
	while (!q.empty()) {
		if ((nowX == goX && nowY == goY)) // 현재 위치와 목표 위치가 동일하면 break
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