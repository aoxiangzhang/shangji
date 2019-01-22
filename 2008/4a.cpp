#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

void split(string s, int a[]) {
    a[0] = atoi(s.substr(0, 4).c_str());
    s = s.substr(5);
    if(s[1] == '-') {
        a[1] = atoi(s.substr(0,1).c_str());
        a[2] = atoi(s.substr(2).c_str());
    }
    else {
        a[1] = atoi(s.substr(0,2).c_str());
        a[2] = atoi(s.substr(3).c_str());
    }
}

int main() {
    int a;
    cout << "请输入模式：";
    cin >> a;
    cout << endl;
    while(1) {
        if(a == 1) {
            string date1, date2;
            int days = 0;
            cout << "请输入两个日期：";
            cin >> date1 >> date2;
            int da1[3], da2[3];
            split(date1, da1);
            split(date2, da2);
            if(da2[0] - da1[0] > 1) {
                for(int i = da1[0]; i < da2[0] - 1; i++) {
                    if(i % 4 == 0 && (da1[1] == 1 || (da1[1] == 2 && da1[2] < 29)))
                        days += 366;
                    else if((i + 1) % 4 == 0 && da1[1] > 2)
                        days += 366;
                    else 
                        days += 365;
                }
            }
            switch(da1[1]) {
                case 1:
                
                    days += 31;
                case 2:
                    if((da2[0] - 1) % 4 == 0)
                        days += 29;
                    else
                        days += 28;
                case 3:
                    days += 31;
                case 4:
                    days += 30;
                case 5:
                    days += 31;
                case 6:
                    days += 30;
                case 7:
                    days += 31;
                case 8: 
                    days += 31;
                case 9:
                    days += 30;
                case 10:
                    days += 31;
                case 11:
                    days += 30;
                case 12:
                    days += 31;
                default: 
                    break;
            }
            days -= da1[2];
            switch(da2[1]) {
                case 11:
                    days += 31;
                case 10:
                    days += 30;
                case 9:
                    days += 31;
                case 8:
                    days += 30;
                case 7: 
                    days += 31;
                case 6:
                    days += 31;
                case 5:
                    days += 30;
                case 4:
                    days += 31;
                case 3:
                    days += 30;
                case 2:
                    days += 31;
                case 1:
                    if((da2[0]) % 4 == 0)
                        days += 29;
                    else
                        days += 28;
                default: 
                    break;
            }
            days += da2[2];
            cout << "\nall: " << days << "days" << endl;
        }
        else if(a == 2) {
            string date1;
            int days;
            int date[3];
            cout << "请输入日期和天数：";
            cin >> date1 >> days;
            while(days > 0) {
                if(date[1] == 1 || date[1] == 3 || date[1] == 5 || date[1] == 7 || date[1] == 8 || date[1] == 10 || date[1] == 12) {
                    if(31 - date[2] <= days) {
                        date[1]++;
                        days -= 32 - date[2];
                        date[2] = 1;
                        if(date[1] == 13)
                            date[0]++;  
                    }
                    else {
                        date[2] += days;
                        days = 0;
                    }
                }
                else if(date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11) {
                    if(30 - date[2] <= days) {
                        date[1]++;
                        days -= 31 - date[2];
                        date[2] = 1;
                    }
                    else {
                        date[2] += days;
                        days = 0;
                    }
                }
                else if(date[1] == 2) {
                    if(date[0] % 4 == 0) {
                        if(29 - date[2] <= days) {
                            date[1]++;
                            days -= 30 - date[2];
                            date[2] = 1;
                        }
                        else {
                            date[2] += days;
                            days = 0;
                        }
                    }
                    else {
                        if(28 - date[2] <= days) {
                            date[1]++;
                            days -= 29 - date[2];
                            date[2] = 1;
                        }
                        else {
                            date[2] += days;
                            days = 0;
                        }
                    }
                }
            }
            cout << "\ndate is " << date[0] << "-" << date[1] << "-" << date[2] << endl;
        }
        else {
            break;
        }
    }
}