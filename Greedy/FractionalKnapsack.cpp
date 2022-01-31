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


double fractionalKnapsack(Item arr[], int weight, int len){
    //sort array berdasarkan rasio
    //rasio berdasarkan value / weight, berarti yang diprioritaskan
    //adalah yang valuenya paling banyak per weight
    sort(arr, arr + len, ratioComparison);

    //inisialisasi weight awal dan jawaban
    int currentWeight = 0;
    double value = 0.0;

    //mari kita coba greed by density
    for(int i = 0; i < len; i++){
        //tambahin kalo muat
        if (currentWeight + arr[i].weight <= weight){
            currentWeight += arr[i].weight;
            value += (double)arr[i].value;
            cout << "Item " << i << " added (frac: 1)" << endl;
        //kalo ngga muat, kita hitung fraction dari selisih sisa berat per weight dari item itu
        //valuenya dikalikan dengan fraction itu, terus ditambahin ke 
        } else {
            double fraction = ((double)weight - (double)currentWeight) / (double)arr[i].weight;
            if (fraction){
                value += (double)arr[i].value * fraction;
                currentWeight += arr[i].weight * fraction;
                cout << "Item " << i << " added (frac: " << fraction << ")" << endl;
            } else {
                cout << "Item " << i << " not added!" << endl;
            }
        }
    }
    return value;
}

int main(){
    //value, weight
    int weight = 20;
    Item arr[] = {Item(25, 18), Item(24, 15), Item(15, 10)};
    int len = sizeof(arr) / sizeof(arr[0]);
    cout << "Max fractional knapsack value: " << endl;
    cout << fractionalKnapsack(arr, weight, len);
}