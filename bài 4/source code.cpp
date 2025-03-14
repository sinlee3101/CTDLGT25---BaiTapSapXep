#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace chrono;

vector<int> readData(const string& filename) {
    ifstream file(filename);
    vector<int> data;
    int num;
    while (file >> num) {
        data.push_back(num);
    }
    return data;
}

void writeData(const string& filename, const vector<int>& data) {
    ofstream file(filename);
    for (int num : data) {
        file << num << endl;
    }
}

void interchangeSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void bubbleSort(vector<int>& arr);
void quickSort(vector<int>& arr, int left, int right);
void mergeSort(vector<int>& arr, int left, int right);
void heapSort(vector<int>& arr);

// Đo thời gian chạy
template <typename Func>
double measureTime(vector<int> data, Func sortFunc) {
    auto start = high_resolution_clock::now();
    sortFunc(data);
    auto end = high_resolution_clock::now();
    return duration<double, milli>(end - start).count();
}

int main() {
    vector<int> data = readData("input.txt");
    vector<pair<string, function<void(vector<int>&)>>> algorithms = {
        {"Interchange Sort", interchangeSort},
        {"Selection Sort", selectionSort},
        {"Insertion Sort", insertionSort},
        {"Bubble Sort", bubbleSort},
        {"Quick Sort", [](vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }},
        {"Merge Sort", [](vector<int>& arr) { mergeSort(arr, 0, arr.size() - 1); }},
        {"Heap Sort", heapSort}
    };
    ofstream resultFile("output.txt");

    for (auto& algo : algorithms) {
        vector<int> dataCopy = data;
        double timeTaken = measureTime(dataCopy, algo.second);
        resultFile << algo.first << ": " << timeTaken << " ms\n";
        writeData(algo.first + "_result.txt", dataCopy);
    }
    resultFile.close();
    cout << "Hoàn thành đo thời gian và lưu kết quả." << endl;
    return 0;
}
