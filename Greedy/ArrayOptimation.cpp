//pencarian hasil perkalian terbesar dan terkecil dari array
#include <bits/stdc++.h>
using namespace std;

// untuk pencarian terkecil kita bisa rule out kalau: 
// 1. misalnya banyaknya bilangan negatif ada genap, 
//         hasil perkalian terkecil adalah hasil perkalian semua bilangan 
//         kecuali bilangan negatif terbesar
// 2. misalnya banyaknya bilangan negatif ada ganjil,
//         hasil perkalian terkecil adalah hasil perkalian semua bilangan
// 3. kalau semuanya positif dan 0, 
//         hasil perkalian terkecil = 0

int minProduct(int arr[], int len){
    if (len == 1){ //misalnya panjang array 1, return elemen pertama
        return arr[0];
    }
    vector<int> integers;
    //cari banyaknyan bilangan negatif / 0
    int maximum_negative = INT_MIN; 
    int minimum_positive = INT_MAX;
    int count_zero = 0; 
    int count_negative = 0;
    int ans = 1;

    for(int i = 0; i < len; i++){
        if (arr[i] == 0){
            count_zero++;
        } else {
            if (arr[i] < 0){
                count_negative++;
                maximum_negative = max(maximum_negative, arr[i]);
            } else {
                minimum_positive = min(minimum_positive, arr[i]);
            }
            ans *= arr[i];
            integers.push_back(arr[i]);
        }
    }
    //kalau misalnya semuanya 0 atau gada yang negatif, return 0
    if (count_zero == len || (count_negative == 0 && count_zero > 0)){
        return 0;
    }
    //kalo gada yang negatif, return minimal positif
    if (count_negative == 0){
        return minimum_positive;
    }
    //kalo bilangan negatif ada genap, ans = ans / max_neg
    //karena kita terus mengalikan bilangan positif dan negatif ke ans,
    //kalau jumlah negatifnya genap berarti hasilnya akan positif, maka perlu dibagi lagi dgn max neg
    //kalau jumlah negatifnya ganjil berarti udah bener
    if (count_negative % 2 == 0){
        ans /= maximum_negative;
        integers.erase(remove(integers.begin(), integers.end(), maximum_negative), integers.end());
    }
    return ans;
}

//penerapan maximum subset rada mirip tapi ada beberapa perubahan:
//1. kita gaperlu max positif lagi 
//2. kalau semuanya negatif, hasil kali semua juga
//3. kalau negatif ada 1 dan sisanya 0, return 0
//4. kalau negatif ada ganjil dan sisanya 0, hasil = jumlah kali / maximum negative
int maxProduct(int arr[], int len){
    if (len == 1){ //misalnya panjang array 1, return elemen pertama
        return arr[0];
    }
    //cari banyaknyan bilangan negatif / 0
    int maximum_negative = INT_MIN; 
    int count_zero = 0; 
    int count_negative = 0;
    int ans = 1;
    vector<int> integers;

    for(int i = 0; i < len; i++){
        if (arr[i] == 0){
            count_zero++;
        } else {
            if (arr[i] < 0){
                count_negative++;
                maximum_negative = max(maximum_negative, arr[i]);
            }
            ans *= arr[i];
            integers.push_back(arr[i]);
        }
    }
    //kalau misalnya semuanya 0, return 0
    if (count_zero == len){
        return 0;
    }
    //kalo jumlah negatif ganjil,
    if (count_negative % 2 != 0){
        //kalo negatifnya cuman 1, return 0 karena hasil kali neagtif
        if (count_negative == 1 && count_zero + count_negative == len){
            return 0;
        } else {
            ans /= maximum_negative;
            integers.erase(remove(integers.begin(), integers.end(), maximum_negative), integers.end());
            //for(int i : integers) cout << i << " ";
        }
    }
    return ans;
}

int main(){
    int a[] = { -1, -1, -2, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Minimum prod of array: " << minProduct(a, n)<< endl;
    cout << "Maximum prod of array: " << maxProduct(a, n) << endl;;
    return 0;
}