// algorithm::transform

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string in, a;
    cin >> a;
    in = a;
    int left, right, length = in.length() - 1, flag, count = 0;
    transform(in.begin(), in.end(), in.begin(), ::tolower);
    while(length >= 0) {
        for(int i = 0; i < in.length() - length; i++) {
            left = i;
            right = i + length;
            flag = 1;
            while(left <= right) {
                if(in[left] != in[right]) {
                    flag = 0;
                    break;
                }
                left++;
                right--;
            }
            if(flag == 1)
                count++;
        }
        if(count != 0)
            break;
        length--;
    }
    cout << a << ' ' << length + 1 << ' ' << count << endl;
    
    return 0;
}