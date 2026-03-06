#include <vector>
#include <iostream>

using namespace std;

void printVector(vector<int> array)
{
    // cout << "[";
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ";";
    }

    cout << endl;
}
void print2DVector(vector<vector<int>> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        printVector(array[i]);
    }
}

// vector<int> countingsort(vector<int> array)
// {
//     vector<int> count(4, 0);
//     for (int i = 0; i < array.size(); i++)
//     {
//         count[array[i]]++;
//     }

//     // cout << "Count Array: ";
//     // printVector(count);
//     // cout << endl;

//     vector<int> new_array = {};

//     for (int i = 0; i < count.size(); i++)
//     {
//         // cout << "count: " << i << ", " << "Count[i]: " << count[i] << endl;
//         for (int j = 0; j < count[i]; j++)
//         {
//             new_array.push_back(i);
//         };
//     };
//     return new_array;
// }
void countingSort2(vector<vector<int>> &array, int col)
{
    vector<int> count(4, 0);

    for (int i = 0; i < array.size(); i++)
    {
        count[array[i][col]]++;
    }
    int row = 0;
    for (int value = 0; value < count.size(); value++)
    {
        for (int times = 0; times < count[value]; times++)
        {
            array[row][col] = value;
            row++;
        }
    }
}

// vector<int> getColumn(const vector<vector<int>> &array, int col)
// {
//     vector<int> column;

//     for (int row = 0; row < array.size(); row++)
//     {
//         column.push_back(array[row][col]);
//     }

//     return column;
// }
void sortArray(vector<vector<int>> &array)
{

    for (int i = 0; i < array[0].size(); i++)
    {
        countingSort2(array, i);
    }
    print2DVector(array);
};
int main()
{
    // int num = 5;

    // vector<vector<int>> array = {
    //     {3, 3, 3, 3, 3, 2, 2, 2, 2, 2},
    //     {2, 3, 2, 2, 2, 2, 2, 2, 2, 2},
    //     {1, 3, 0, 0, 2, 1, 0, 0, 0, 0},
    //     {1, 3, 0, 0, 2, 2, 0, 0, 0, 0},
    //     {2, 3, 2, 1, 2, 2, 2, 2, 2, 2},

    // };

    int n;

    cin >> n;

    vector<vector<int>> array;

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            int temp2;
            cin >> temp2;
            temp.push_back(temp2);
        }
        array.push_back(temp);
    }


    // vector<int> start = array[0];
    // cout << "Base array: ";
    // printVector(start);
    // cout << endl;
    // cout << "Count: ";
    // printVector(countingsort(start));

    sortArray(array);

    return 0;
}