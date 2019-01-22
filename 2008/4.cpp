#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int list[5000][12][31] = {0};
int month[2][12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
};

void split(string s, int a[]) {
    for(int i = 0; i < 5; i++)
        if(s[i] == '-'){
            a[0] = atoi(s.substr(0, i).c_str());
            s = s.substr(i+1);
        }
    
    if(s[1] == '-') {
        a[1] = atoi(s.substr(0,1).c_str());
        a[2] = atoi(s.substr(2).c_str());
    }
    else {
        a[1] = atoi(s.substr(0,2).c_str());
        a[2] = atoi(s.substr(3).c_str());
    }
}

void create() {
    int count = 1;
    int flag = 0;
    for(int y = 0; y < 5000; y++) {
        if(!((y + 1) % 4 == 0 && (y + 1) % 100 != 0) || (y + 1) % 400 == 0)
            flag = 0;
        else
            flag = 1;
        for(int m = 0; m < 12; m++)
            for(int d = 0; d < 31; d++) 
                if(d < month[flag][m])
                    list[y][m][d] = count++;
                else 
                    break; 
    }
}

int main() {
    create();
    int a;
    while(1) {
        cout << "请选择模式：";
        cin >> a;
        cout << endl;
        if(a == 1) {
            string date1, date2;
            cout << "请输入两个日期：";
            cin >> date1 >> date2;
            int d1[3], d2[3];
            split(date1, d1);
            split(date2, d2);
            cout << "\nday is " << list[d2[0] - 1][d2[1] - 1][d2[2] - 1] -  list[d1[0] - 1][d1[1] - 1][d1[2] - 1] << endl;
        }
        else if(a == 2) {
            string date;
            int days;
            cout << "请输入日期和天数：";
            cin >> date >> days;
            int d[3];
            split(date, d);
            int count = list[d[0] - 1][d[1] - 1][d[2] - 1] + days;
            for(int judge = 1, y = d[0] - 1 + days / 366; y < 5000 && judge; y++)
                for(int m = d[1] - 1 + (days % 366) / 31; m < 12 && judge; m++)
                    for(int day = 0; day < 31 && judge; day++)
                        if(list[y][m][day] == count) {
                            cout << "date is " << y + 1 << "-" << m + 1 << "-" << day + 1 << endl;
                            judge = 0;
                        }
        }
        else
            break;
    }
    return 0;
}