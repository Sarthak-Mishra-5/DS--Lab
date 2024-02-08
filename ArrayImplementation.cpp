#include <iostream>
using namespace std;

void display1D(int arr[], int n) {
    cout << "1D Array Elements:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void display2D(int arr[][3], int rows, int cols) {
    cout << "2D Array Elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to display the elements of a 3D array
void display3D(int arr[][3][3], int dim1, int dim2, int dim3) {
    cout << "3D Array Elements:" << endl;
    for (int i = 0; i < dim1; i++) {
        for (int j = 0; j < dim2; j++) {
            for (int k = 0; k < dim3; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    // 1D Array
    const int size1D = 5;
    int arr1D[size1D] = {1, 2, 3, 4, 5};
    display1D(arr1D, size1D);

    // 2D Array
    const int rows2D = 3;
    const int cols2D = 3;
    int arr2D[rows2D][cols2D] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    display2D(arr2D, rows2D, cols2D);

    // 3D Array
    const int dim13D = 2;
    const int dim23D = 3;
    const int dim33D = 3;
    int arr3D[dim13D][dim23D][dim33D] = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}}
    };
    display3D(arr3D, dim13D, dim23D, dim33D);

    return 0;
}
