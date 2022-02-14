#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int left, int mid, int right){
    int *leftArr = new int[mid - left + 1];
    int *rightArr = new int[right - mid];

    for(int i = 0; i < (mid - left + 1); i++){ //pengisian array kiri
        leftArr[i] = array[left + i];
    }

    for(int j = 0; j < (right - mid); j++){ // pengisian array kanan
        rightArr[j] = array[mid + 1 + j];
    }

    int mergeIndex = left;
    int leftIndex = 0;
    int rightIndex = 0;
    
    //proses merging, mirip prioqueue, yang lebih kecil maju duluan
    while (leftIndex < (mid-left+1) && rightIndex < (right - mid)){
        if (leftArr[leftIndex] <= rightArr[rightIndex]){
            array[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }
        else{
            array[mergeIndex] = rightArr[rightIndex];
            rightIndex++;
        }
        mergeIndex++;
    }

    //habiskan kalo masih ada sisa, yang sisa bakal antara leftArr ato rightArr
    //tapi kita habisin dua duanya
    while (leftIndex < (mid-left + 1)){
        array[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    } 
    while (rightIndex < (right - mid)){
        array[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }
}

void mergeSort(int array[], int start, int end){
    if (start >= end) return; //basis

    int mid = start + (end - start)/2;
    mergeSort(array, start, mid); //mergesort dari idx awal ke tengah
    mergeSort(array, mid + 1, end); //mergesort dari tengah ke idx akhir
    merge(array, start, mid, end); //merging
}

int main(){
    int arr[] = {12, 39, 23, 5, 69, 42};
    int length = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, length - 1);

    for(int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
}