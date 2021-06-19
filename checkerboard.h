#ifndef CHECHERBOARD_H
#define CHECHERBOARD_H
#include<iostream>
#include<iomanip>
using namespace std;
class checkerboard {
private:
    char check[19][19] = { " " };
    char play;
public:
    checkerboard();
    ~checkerboard();
    void print();
    bool win(int, int);
    void input(int, int);
    bool confirm(int, int);
    void setplay(char);
};
#endif
