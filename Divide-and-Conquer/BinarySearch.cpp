#include <bits/stdc++.h>
using namespace std;

//binary search untuk array yang sudah terurut
int binSer(int arr[], int startIndex, int arrLength, int key){
    if (arrLength >= startIndex){
        int midIndex = startIndex + ((arrLength - startIndex)/2);

        if (arr[midIndex] == key) return midIndex;                                  //nilai sama, return midIndex
        if (arr[midIndex] > key) return binSer(arr, startIndex, midIndex - 1, key); //nilai lebih besar dari key, cari bagian kiri
        if (arr[midIndex] < key) return binSer(arr, midIndex + 1, arrLength, key); //nilai lebih besar dari key, cari bagian kanan
    }
    return -1; //kalau ga ketemu
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 5;
    int length = sizeof(arr)/sizeof(arr[0]);
    int result = binSer(arr, 0, length, key);
    cout << "Integer " << key << " found in index " << result << endl;
}