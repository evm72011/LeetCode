#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void print(const vector<T>& data) {
    for (const auto& item : data) {
        cout << item << ' ';
    }
    cout << '\n';
}

template<typename T>
void print(vector<vector<T>>& data) {
    for (const auto& vec : data) {
        print(vec);
    }
    cout << '\n';
}
