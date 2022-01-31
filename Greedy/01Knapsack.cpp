#include <iostream>
using namespace std;

//fungsi max dibuatin github copilot, keren gan
int max(int a, int b) {
    return a > b ? a : b;
}

//versi rekur
int knapSackRE(int weight, int weightArr[], int valueArr[], int len){
    //base case nya kalo panjang array 0 / weight 0
    if (len == 0 || weight == 0) return 0;

    //cek dari belakang, kalo weight paling belakang gamuat, kita masukin rekursi
    if (weightArr[len - 1] > weight) return knapSackRE(weight, weightArr, valueArr, len - 1);

    //tapi kalo muat, balikin maksimum dari antara si item itu diinclude ato ngga diinclude
    else {
        return max(valueArr[len - 1] + knapSackRE(weight - weightArr[len - 1], weightArr, valueArr, len - 1),
                   knapSackRE(weight, weightArr, valueArr, len - 1));
    }
}


int main(){
    int valueArr[] = { 60, 100, 120 };
    int weightArr[] =  { 10, 20, 30 };
    int weight = 50;
    int len = sizeof(valueArr) / sizeof(valueArr[0]);
    cout << "Recursive function result: " << knapSackRE(weight, weightArr, valueArr, len);
}


// versi DP nya, dibuatin github copilot juga
// int knapSackDP(int weight, int weightArr[], int valueArr[], int len){
//     int dp[len+1][weight+1];
//     for(int i=0; i<=len; i++){
//         for(int j=0; j<=weight; j++){
//             if(i==0 || j==0){
//                 dp[i][j] = 0;
//             }
//             else if(weightArr[i-1] <= j){
//                 dp[i][j] = max(dp[i-1][j], dp[i-1][j-weightArr[i-1]] + valueArr[i-1]);
//             }
//             else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     return dp[len][weight];
// }