#include <bits/stdc++.h> 
//[IMPORTANT] masukin ini kalo kita mau pake semua standard library di C++
//compilenya bakal lama, jadi dikira" aja kalo mo pake
//ini karena mager include satu satu jadi digabungin
using namespace std;

struct Item{
    int value, weight;
    //constructor
    Item(int val, int weight){
        this->value = val;
        this->weight = weight;
    }
};
//perbandingan rasio value / weight, buat param sort nya
double ratioComparison(struct Item a, struct Item b){
    return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
}


int fractionalKnapsack(Item arr[], int weight, int len){
    //sort array berdasarkan rasio
    //rasio berdasarkan value / weight, berarti yang diprioritaskan
    //adalah yang valuenya paling banyak per weight
    sort(arr, arr + len, ratioComparison);

    //inisialisasi weight awal dan jawaban
    int currentWeight = 0;
    double value = 0;


    //mari kita coba greed by weight
    for(int i = 0; i < len; i++){
        //tambahin kalo muat
        if (currentWeight + arr[i].weight <= weight){
            currentWeight += arr[i].weight;
            value += (double)arr[i].value;
            cout << "Item " << i << " added" << endl;

            
        //kalo ngga muat, kita hitung fraction dari selisih sisa berat per weight dari item itu
        //valuenya dikalikan dengan fraction itu, terus ditambahin ke 
        } else {
            double fraction = (double)(weight - currentWeight) / (double)arr[i].weight;
            value += (double)arr[i].value * fraction;
            cout << "Item " << i << " added (" << fraction << ")" << endl;
        }
    }
    return value;
}


int main(){
    int weight = 50;
    Item arr[] = {Item(60, 10), Item(100, 20), Item(120, 30)};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Max fractional knapsack value: " << endl;
    cout << fractionalKnapsack(arr, weight, len);
}