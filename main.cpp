#include<iostream>
#include<iomanip>
#include"checkerboard.h"
#include"bot.h"
using namespace std;
point p; 
bot computer(p);
int main() {
    int playNumber;

    cout << "歡迎來到五子棋遊戲" << endl << "請輸入遊玩人數 1 or 2" << endl;
    cin >> playNumber;

    if (playNumber == 1) 
    {
        checkerboard round1;//玩家
        int x, y;
        for (int z = 1; z <= 181; z++) 
        {
            cout << endl;
            cout << "第" << z << "回合  " << "黑棋回合" << endl;
            cout << "輸入座標" << endl;
            round1.setplay('X');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) 
            {  //檢查輸入
                cout << "輸入錯誤，重新輸入" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();

            if (round1.win(x, y)) 
            {
                cout << endl << "黑棋獲勝";
                round1.~checkerboard();
                break;
            }

            if (z == 181) 
            {//棋盤已滿
                break;
            }

            cout << endl;
            cout << "第" << z << "回合  " << "白棋回合" << endl;//電腦
            round1.setplay('O');            
            p.setXPoint(x);
            p.setYPoint(y);
            computer.botsee(p, 1);//讀取人類下的棋
            p=computer.botplayer();//return要下的p回來,這裡會出問題!(以解決小寫L跟1傻傻分不清)
            x = p.getXPoint();//輸入X
            y = p.getYPoint();//輸入y
            computer.botsee(p, 2);//讀取剛剛下的棋的情況

            while (round1.confirm(x, y) == false) {  //檢查輸入
                cout << "輸入錯誤，重新輸入" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();
            if (round1.win(x, y)) {
                cout << endl << "白棋獲勝";
                round1.~checkerboard();
                break;
            }


        }
    }
    else if (playNumber == 2)
    {
        checkerboard round1;
        int x, y;
        for (int z = 1; z <= 181; z++) {
            cout << endl;
            cout << "第" << z << "回合  " << "黑棋回合" << endl;
            cout << "輸入座標" << endl;
            round1.setplay('X');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) {  //檢查輸入
                cout << "輸入錯誤，重新輸入" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();

            if (round1.win(x, y)) {
                cout << endl << "黑棋獲勝";
                round1.~checkerboard();
                break;
            }

            if (z == 181) {//棋盤已滿
                break;
            }

            cout << endl;
            cout << "第" << z << "回合  " << "白棋回合" << endl;
            cout << "輸入座標" << endl;
            round1.setplay('O');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) {  //檢查輸入
                cout << "輸入錯誤，重新輸入" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();
            if (round1.win(x, y)) {
                cout << endl << "白棋獲勝";
                round1.~checkerboard();
                break;
            }
        }
    }
}
