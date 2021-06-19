#include "checkerboard.h"
checkerboard::checkerboard() {
	play = 'X';
	for (int i = 0; i < 19; i++) {   //初始棋盤
		for (int j = 0; j < 19; j++) {
			check[i][j] = ' ';
		}
	}
}

checkerboard::~checkerboard() {

}

void checkerboard::print() {

	cout << "     0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18 " << endl;
	for (int i = 0; i < 19; i++) {
		cout << "   ";
		for (int x = 0; x < 19; x++) { //棋盤邊框
			cout << "|---";
		}
		cout << "|" << endl;

		for (int j = 0; j < 19; j++) {
			if (j == 0) {
				cout << setw(2) << i << " |";
			}
			cout << " " << check[i][j] << " |";
		}

		cout << endl;
		if (i == 18) {
			cout << "   ";
			for (int x = 0; x < 19; x++) { //棋盤邊框
				cout << "|---";
			}
			cout << "|";
		}
	}
}

bool checkerboard::win(int x, int y) {
	int on = 0, under = 0, left = 0, right = 0, onRight = 0, onLeft = 0, underRight = 0, underLeft = 0;

	for (int i = 1; i <= 4; i++) {//上
		if (check[x][y + i] == play) {
			on++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//下
		if (check[x][y - i] == play) {
			under++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//左
		if (check[x - i][y] == play) {
			left++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//右
		if (check[x + i][y] == play) {
			right++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//右上
		if (check[x + i][y + i] == play) {
			onRight++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//左上
		if (check[x - i][y + i] == play) {
			onLeft++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//右下
		if (check[x + i][y - i] == play) {
			underRight++;
		}
		else {
			break;
		}
	}

	for (int i = 1; i <= 4; i++) {//左下
		if (check[x + i][y - i] == play) {
			underLeft++;
		}
		else {
			break;
		}
	}

	if ((on + under) == 4 or (left + right) == 4 or (onRight + underLeft) == 4 or (onLeft + underRight) == 4) {
		return true;
	}
	else {
		return false;
	}

}

void checkerboard::input(int x, int y) {
	check[x][y] = play;
}

bool checkerboard::confirm(int x, int y) {

	if (x < 0 or x>19) {
		return false;
	}
	if (y < 0 or y>19) {
		return false;
	}

	if (check[x][y] == ' ') {
		return true;
	}
	else {
		return false;
	}
}

void checkerboard::setplay(char play) {
	this->play = play;
}