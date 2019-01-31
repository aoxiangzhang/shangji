// 注意数组是从0开始的

#include<iostream>
using namespace std;

int nums[11] = {0, -36, -25, 0, 12, 14, 29, 35, 47, 76, 100};

int main() {
    int target, left = 1, right = 10, half, count = 0;
    cout << "请输入要查找的数据：";
    cin >> target;
    while(1) {
        count++;
        half = (left + right) / 2;
        if(nums[half] < target)
            left = half + 1;
        else if(nums[half] > target)
            right = half - 1;
        else {
            cout << target << "是第" << half << "个数, 查找次数为" << count << endl;
            break;
        }
        if(right < left) {
            cout << "查找失败" << endl;
            break;
        }
    }
}