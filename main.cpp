#include<iostream>
#include<iomanip>
#include"checkerboard.h"
#include"bot.h"
using namespace std;
point p; 
bot computer(p);
int main() {
    int playNumber;

    cout << "�w��Ө줭�l�ѹC��" << endl << "�п�J�C���H�� 1 or 2" << endl;
    cin >> playNumber;

    if (playNumber == 1) 
    {
        checkerboard round1;//���a
        int x, y;
        for (int z = 1; z <= 181; z++) 
        {
            cout << endl;
            cout << "��" << z << "�^�X  " << "�´Ѧ^�X" << endl;
            cout << "��J�y��" << endl;
            round1.setplay('X');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) 
            {  //�ˬd��J
                cout << "��J���~�A���s��J" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();

            if (round1.win(x, y)) 
            {
                cout << endl << "�´����";
                round1.~checkerboard();
                break;
            }

            if (z == 181) 
            {//�ѽL�w��
                break;
            }

            cout << endl;
            cout << "��" << z << "�^�X  " << "�մѦ^�X" << endl;//�q��
            round1.setplay('O');            
            p.setXPoint(x);
            p.setYPoint(y);
            computer.botsee(p, 1);//Ū���H���U����
            p=computer.botplayer();//return�n�U��p�^��,�o�̷|�X���D!(�H�ѨM�p�gL��1�̶̤����M)
            x = p.getXPoint();//��JX
            y = p.getYPoint();//��Jy
            computer.botsee(p, 2);//Ū�����U���Ѫ����p

            while (round1.confirm(x, y) == false) {  //�ˬd��J
                cout << "��J���~�A���s��J" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();
            if (round1.win(x, y)) {
                cout << endl << "�մ����";
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
            cout << "��" << z << "�^�X  " << "�´Ѧ^�X" << endl;
            cout << "��J�y��" << endl;
            round1.setplay('X');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) {  //�ˬd��J
                cout << "��J���~�A���s��J" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();

            if (round1.win(x, y)) {
                cout << endl << "�´����";
                round1.~checkerboard();
                break;
            }

            if (z == 181) {//�ѽL�w��
                break;
            }

            cout << endl;
            cout << "��" << z << "�^�X  " << "�մѦ^�X" << endl;
            cout << "��J�y��" << endl;
            round1.setplay('O');
            cin >> x >> y;

            while (round1.confirm(x, y) == false) {  //�ˬd��J
                cout << "��J���~�A���s��J" << endl;
                cin >> x >> y;
            }

            round1.input(x, y);
            round1.print();
            if (round1.win(x, y)) {
                cout << endl << "�մ����";
                round1.~checkerboard();
                break;
            }
        }
    }
}
