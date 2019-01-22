#include"2.cpp"
#include<iostream>
using namespace std;


class CTriangle {
    public:
        CPoint a;
        CPoint b;
        CPoint c;

        CTriangle(double, double, double, double, double, double);
        bool judgeRight();
        double perimeter();
};

CTriangle::CTriangle(double aX, double aY, double bX, double bY, double cX, double cY) {
    a.setPoint(aX, aY);
    b.setPoint(bX, bY);
    c.setPoint(cX, cY);
}

bool CTriangle::judgeRight() {
    double a = CTriangle::a / CTriangle::b;
    double b = CTriangle::b / CTriangle::c;
    double c = CTriangle::c / CTriangle::a;
    double temp;
    if(a < b){
        temp = b;
        b = a;
        a = temp;
    }
    if(a < c){
        temp = c;
        c = a;
        a = temp;
    }
    if(a == b + c)
        return true;
    else
        return false;
}

double CTriangle::perimeter() {
    return (a - b) + (b - c) + (c - a);
}

int main()
{
    CTriangle x = CTriangle(0, 1, 1, 0, 0, 0);
    cout << x.judgeRight() << endl;
    cout << x.perimeter() << endl;
    return 0;
}
