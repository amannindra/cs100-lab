
#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int i = l + 1;
    int j = r;

    while (true)
    {
        while (i <= r && arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[l], arr[j]);
    return j;
}

void sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);
        sort(arr, l, pivot - 1);
        sort(arr, pivot + 1, r);
    }
}

int main()
{
    int n;

    cin >> n;

    vector<int> array;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    sort(array, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ";";
    };
    cout << endl;

    return 0;
}