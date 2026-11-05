#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

int N = 10000;
long long sum1(const vector<int>& a) {
    long long sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += a[i * N + j];
    return sum;
}
long long sum2(const vector<int>& a) {
    long long sum = 0;
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            sum += a[i * N + j];
    return sum;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<int> a(N*N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            a[i * N + j] = (i + j) % 100;
    auto start = chrono::steady_clock::now();
    long long s1 = sum1(a);
    auto end = chrono::steady_clock::now();
    double t1 = chrono::duration<double>(end - start).count();

    start = chrono::steady_clock::now();
    long long s2 = sum2(a);
    end = chrono::steady_clock::now();
    double t2 = chrono::duration<double>(end - start).count();

    cout << "Сумма 1: " << s1 << endl;
    cout << "Время 1: " << t1 << " секунд" << endl;
    cout << "Сумма 2: " << s2 << endl;
    cout << "Время 2: " << t2 << " секунд" << endl;
    return 0;
}
