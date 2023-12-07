#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void MinFinder(vector<int>& A) 
{
    int L = A.size() - 1;
    int NextIterPoint = 0;
    // Loop until the entire array is sorted
    while (NextIterPoint < L) 
    {
        int PositionOfMinValue = NextIterPoint;
        int minValue = A[PositionOfMinValue];
        // Find the minimum value and its position in the unsorted portion
        for (int i = NextIterPoint + 1; i <= L; ++i) 
        {
            if (minValue > A[i]) 
            {
                minValue = A[i];
                PositionOfMinValue = i;
            }
        }
        // Rotate the array to place the minimum value in its correct position
        rotate(A.begin() + NextIterPoint, A.begin() + PositionOfMinValue, A.begin() + PositionOfMinValue + 1);
        A[NextIterPoint] = minValue;
        ++NextIterPoint;
    }

    cout << "Sorted array: ";
    for (int num : A) 
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Minimum value: " << A[0] << endl;
}

int main() 
{
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) 
    {
        cin >> arr[i];
    }

    MinFinder(arr);

    return 0;
}
