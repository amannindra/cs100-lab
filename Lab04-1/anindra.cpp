
#include <vector>
#include <iostream>

using namespace std;

void heapify(vector<int> &arr, int n, int i)
{

    int big = i;
    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[big])
        big = left;

    if (right < n && arr[right] > arr[big])
        big = right;

    if (big != i)
    {
        swap(arr[i], arr[big]);
        heapify(arr, n, big);
    }
}

void test(vector<int> &array, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {

        // Move current root to end
        swap(array[0], array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
    }


};

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
    test(array, n);

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << ";";
    };
    cout << endl;
    return 0;
}