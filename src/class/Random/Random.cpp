// // #include "Card.hpp"
// // #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <random>
// #include <vector>

// using namespace std;

// template <class T>
// T getRandomIndex(const vector<T>& vec) {
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<> dis(0, vec.size() - 1);

    
//     vector<T> shuffleVec(vec);
//     shuffle(shuffleVec.begin(), shuffleVec.end(), gen);


//     for (const auto& elem : shuffleVec) {
//         if (find(vec.begin(), vec.end(), elem) != vec.end()) {
//             return elem;
//         }
//     }

    
//     return T();
// }

// #include <iostream>
// #include <vector>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// template<typename T>
// int randomIndex(const vector<T>& vec) {
//     srand(time(nullptr)); 
//     return rand() % vec.size(); 
// }

// int main() {
//     vector<int> v {1, 2, 3, 4, 5, 6, 7, 8};
//     int idx = randomIndex(v);
//     cout << "Indeks acak: " << idx << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T>
void randomIndex(const vector<T>& vec, vector<int>& idx) {
    srand(time(nullptr)); 
    vector<int> randomIdx(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        randomIdx[i] = i;
    }
    for (int i = 0; i < vec.size(); i++) {
        int randIndex = i + (rand() % (vec.size() - i));
        idx.push_back(randomIdx[randIndex]);
        swap(randomIdx[i], randomIdx[randIndex]);
    }
}

int main() {
    vector<string> players {"A", "B", "C", "D", "E"};
    vector<int> idx ;
    vector<int> idx2 {1, 2, 3, 4, 5, 6, 7, 8};
    randomIndex(idx2, idx);
    for (int i = 0; i < players.size(); i++) {
        cout << players[i] << " get index " << idx[i] << endl;
    }
    return 0;
}

