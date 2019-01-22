#include<iostream>
#include<cmath>
using namespace std;

class CPoint {
    private:
        double x, y;
    public:
        CPoint();
        CPoint(double, double);
        void setPoint(double, double);
        double operator-( CPoint&)const;
        double operator/(const CPoint&);
};

CPoint::CPoint(){
    x = 0;
    y = 0;
}

CPoint::CPoint(double a, double b){
    x = a;
    y = b;
}

void CPoint::setPoint(double a, double b) {
    x = a;
    y = b;
}

double CPoint::operator-( CPoint& p)const{
    return sqrt(pow(x-p.x, 2) + pow(y-p.y, 2));
}

double CPoint::operator/(const CPoint& p){
    return pow(x-p.x, 2) + pow(y-p.y, 2);
}

int main()
{
    CPoint a = CPoint(2, 2);
    CPoint b = CPoint(5, 6);

    cout << a - b << endl;
    return 0;
}
