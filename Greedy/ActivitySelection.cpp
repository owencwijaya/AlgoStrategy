#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Activities(int s[], int f[], int len){
    //aktivitas pertama akan lebih duluan dpilih
    int ca = 0;
    cout << ca + 1;
    //mulai dari 1 karena aktivitas pertama dipanggil
    //iterasi setiap acara
    for(int i = 1; i < len; i++){
        //kalau ada acara yang waktu mulainya
        //>= waktu akhir acara lagi diattend,
        if (s[i] >= f[ca]){
            //output index acara itu,
            //ganti acara yang sedang dihadirin
            //degn acara itu
            cout << " " << i + 1;
            ca = i;
        }
    }
}

int main(){
    int startTime[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    int finishTime[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};

    //cara hitung panjang array
    int len = sizeof(startTime) / sizeof(startTime[0]);
    Activities(startTime, finishTime, len);
    return 0;
}
