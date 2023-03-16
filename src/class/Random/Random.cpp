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