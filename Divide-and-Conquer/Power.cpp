#include <bits/stdc++.h>
using namespace std;

int powerOf(int x, int pangkat){
    if (pangkat == 0) return 1;
    if (pangkat % 2 == 0) return powerOf(x, pangkat/2) * powerOf(x, pangkat/2);
    if (pangkat % 2 != 0) return powerOf(x, pangkat/2) * powerOf(x, pangkat/2) * x;
}

int main(){
    cout << powerOf(2, 3) << endl;
}