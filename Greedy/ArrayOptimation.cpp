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