// algorithm sort���㷨
// cstring �� string��ͬ�� c++11string��string��ͬ��string�Ƕ�����c���Ժ���stoi�� strcpy���в�����Ϊ�������룬��Ҫcstring��c_strת��Ϊ��

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
        cout << "���������" << endl;
        cin >> order;
        switch(order) {
            case 1:
                cout << "������������";
                cin >> name;
                cout << "\n������ѧ�ţ�";
                cin >> num;
                cout << endl;
                stu.setStudent(num, name);
                stus.push_back(stu);
                break;
            case 2:
                cout << "������ѧ�ţ�";
                cin >> num;
                for(s = stus.begin(); s != stus.end(); s++) {
                    if(s->num == num) {
                        cout << "������" << s->name << " ѧ�ţ�" << s->num << endl;
                        break;
                    }
                }
                cout << "������ɣ�" << endl;
                break;
            case 3:
                cout << "��ѡ������ʽ��";
                cin >> order;
                cout << endl;
                if(order == 1){
                    sort(stus.begin(), stus.end(), com1);
                }
                else if(order == 2) {
                    sort(stus.begin(), stus.end(), com2);
                }
                else {
                    cout << "������Ч��" << endl;
                    break;
                }
                for(s = stus.begin(); s != stus.end(); s++) {
                    cout << s->name << "    " << s->num << endl;
                }
                break;
            default:
                cout << "������Ч��" << endl;
                break;
        }
        if(order == 4)
            break;
    }
    return 0;
}
