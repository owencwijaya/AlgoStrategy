#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int pivotIndexAfterPlacing(int arr[], int start, int end){
    int pivot = arr[end]; 
    //ambil nilai akhir array jadi pivotnya
    //jadinya kita ngebandingin selalu sama yang terakhir
    int i = start - 1; //ini anggepannya jadi penanda indeks 
                       //untuk bagian kiri pivot

    for (int j = start; j < end; j++){
        if (arr[j] < pivot){ 
            i++;
            swap(&arr[i], &arr[j]); //swapping nilai
        }
    }
    //setelah semua selesai, swap pivot dengan arr[i];
    swap(&arr[i + 1], &arr[end]);
    //pivot sekarang ada di i + 1
    return (i + 1);
}

void quickSort(int arr[], int start, int end){
    if (start < end){
        int pivotIndex = pivotIndexAfterPlacing(arr, start, end);
        //bagi array jadi dua, sort sebelum partisi dan sesudah partisi
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

int main(){
    int arr[] = {12, 39, 23, 5, 69, 42};
    int length = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, length - 1);

    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
}