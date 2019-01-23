#include<iostream>
using namespace std;

int **a;
int order;

void findL(int x, int y, int count) {
    a[x][y] = count++;
    if(a[(x+1)%order][(y+1)%order] == 0)
        findL((x+1)%order, (y+1)%order, count);
    else if(a[(x+2)%order][y] == 0)
        findL((x+2)%order, y, count);
    else ;
}

int main()
{
    cin >> order;
    a = new int*[order];
    for(int i = 0; i < order; i++){
        a[i] = new int[order];
        for(int j = 0; j < order; j++)
            a[i][j] = 0;
    }
        
    findL(order / 2 + 1, order / 2, 1);
    for(int x = 0; x < order; x++) {
        for(int y = 0; y < order; y++)
            cout << a[x][y] << "    ";
        cout << endl;
    }
    return 0;
}

