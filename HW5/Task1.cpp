#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 3, 5, -5, 12, 6, -8, -11};
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [](int x){
        return x < 0;
    }), numbers.end());
    sort(numbers.begin(), numbers.end());
    for (int elem: numbers) {
        cout << elem << " ";
    }
}
