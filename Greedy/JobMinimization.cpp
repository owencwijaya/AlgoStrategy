//diberikan pekerjaan 1 sampai N
//Ti = waktu pekerjaan
//Li = loss per delay hari
//bagaimana cara minimisasinya?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int> > job;

bool checkWeight(job a, job b){
    //bandingkan banyak loss pertama jika aktivitas kedua
    //dilakukan sebanyak time kedua, and vice versa 
    return (a.second.first * b.second.second) >
    (a.second.second * b.second.first);
}

void findOptimal(int T[], int L[], int len){
    vector<job> list;
    for(int i = 0; i < len; i++){
        //add on end (push_back)
        //pair baru
        list.push_back(make_pair(i + 1, make_pair(L[i], T[i])));
    }

    //stable sort dari awal sampe akhir 
    //pake checkWeight
    stable_sort(list.begin(), list.end(), checkWeight);

    cout << "Urutan pekerjaan di optimal sequence:" << endl;
    for (job j : list) cout << j.first << " "; 
}

int main(){
    int time[] = {2, 4, 1, 3, 2};
    int loss[] = {1, 2, 3, 5, 6};
    int len = sizeof(loss) / sizeof(loss[0]);
    findOptimal(time, loss, len);
}
