#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n, int** solArr) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            arr[x][y] == 1 && solArr[x][y] == 0);
}

bool findPath(int** arr, int x, int y, int n, int** solArr) {
    if (x == n - 1 && y == n - 1 && arr[x][y] == 1) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solArr)) {
        solArr[x][y] = 1;

        if (findPath(arr, x, y + 1, n, solArr))
            return true;
        if (findPath(arr, x + 1, y, n, solArr))
            return true;
        if (findPath(arr, x, y - 1, n, solArr))
            return true;
        if (findPath(arr, x - 1, y, n, solArr))
            return true;
            
        solArr[x][y] = 0; // Answer (b)
    }

    return false;
}

int main() {
    int n = 4;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
        arr[i] = new int[n];

    int input[4][4] = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {0, 1, 1, 1}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = input[i][j];

    int** solArr = new int*[n];
    for (int i = 0; i < n; i++) {
        solArr[i] = new int[n];
        for (int j = 0; j < n; j++)
            solArr[i][j] = 0;
    }
	
    if (findPath(arr, 0, 0, n, solArr)) {
        cout << "Path found:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << solArr[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "No path exists.\n";
    }


}


