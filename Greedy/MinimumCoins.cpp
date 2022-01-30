//steps:
//1. urutkan array koin mengecil
//2. init result
//3. cari koin yang muat dengan nominal
//4. kurangi nominal dengan koin
//5. ulangin sampe 0
//6. kalo ga 0, coba lagi

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
int length = sizeof(coins) / sizeof(coins[0]);

typedef pair<int, int> coin;

void findMinimum(int nominal){
    vector<coin> ans;
    int count;
    int totalcount = 0;
    cout << "To find " << nominal << " coins, the minimum amount needed is ";
    for (int i = length - 1; i >= 0; i--){
        while (nominal >= coins[i]){
            nominal -= coins[i];
            count++;
        }
        if (count > 0)
            ans.push_back(make_pair(coins[i], count));
            totalcount += count;
            count = 0;
    }
    cout << totalcount << " coins." << endl;

    for (int i = 0; i < ans.size(); i++){
        cout << "- " << ans[i].second << " " << ans[i].first << " coins" << endl;
    }
}

int main(){
    int nominal = 0;
    cout << "Input nominal: ";
    cin >> nominal;
    findMinimum(nominal);
}