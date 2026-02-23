#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



void wierdPrint(vector<int> &arr, int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ";";
  }
  cout << endl;
}


void insertionSort(vector<int> &arr)
{
    int l = 2;
     // cout << arr[0] << ";" << endl;
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            
        }
        arr[j + 1] = key;
        wierdPrint(arr, l);
        l += 1;
    }
}

int main()
{

    vector<int> arr;
    int n;
    cin >> n;
    int i = 0;
    while (i < n) {
        int x;
        cin >> x;
        arr.push_back(x);
        i++;
    }



    // printArray(arr);
    insertionSort(arr);
    // printArray(arr);

    return 0;
}