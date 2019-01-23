// algorithm sort等算法
// cstring 和 string不同， c++11string和string不同，string是对象，在c语言函数stoi， strcpy等中不能作为参数输入，需要cstring中c_str转化为串

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

class Student {
    public: 
        int num;
        char name[10];

        Student();
        void setStudent(int, char * na);
};

Student::Student(){

}

void Student::setStudent(int nu, char *na) {
    num = nu;
    strcpy(name, na);
}

bool com1(Student a, Student b) {
    return a.num < b.num;
}

bool com2(Student a, Student b) {
    return a.num > b.num;
}


int main()
{
    vector<Student> stus;
    vector<Student>::iterator s;
    Student stu;
    int order;
    int num;
    char name[10];
    while(true) {
        cout << "请输入命令：" << endl;
        cin >> order;
        switch(order) {
            case 1:
                cout << "请输入姓名：";
                cin >> name;
                cout << "\n请输入学号：";
                cin >> num;
                cout << endl;
                stu.setStudent(num, name);
                stus.push_back(stu);
                break;
            case 2:
                cout << "请输入学号：";
                cin >> num;
                for(s = stus.begin(); s != stus.end(); s++) {
                    if(s->num == num) {
                        cout << "姓名：" << s->name << " 学号：" << s->num << endl;
                        break;
                    }
                }
                cout << "查找完成！" << endl;
                break;
            case 3:
                cout << "请选择排序方式：";
                cin >> order;
                cout << endl;
                if(order == 1){
                    sort(stus.begin(), stus.end(), com1);
                }
                else if(order == 2) {
                    sort(stus.begin(), stus.end(), com2);
                }
                else {
                    cout << "输入无效！" << endl;
                    break;
                }
                for(s = stus.begin(); s != stus.end(); s++) {
                    cout << s->name << "    " << s->num << endl;
                }
                break;
            default:
                cout << "输入无效！" << endl;
                break;
        }
        if(order == 4)
            break;
    }
    return 0;
}
