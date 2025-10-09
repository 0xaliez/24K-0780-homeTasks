#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n, int** solArr) {
    return (x >= 0 && y >= 0 && x < n && y < n &&
            arr[x][y] == 1 && solArr[x][y] == 0);
}

bool findPath(int** arr, int x, int y, int n, int** solArr) {

    if (x == 2 && y == 2) {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe(arr, x, y, n, solArr)) {
        solArr[x][y] = 1;
        if (findPath(arr, x + 1, y, n, solArr)) return true;
        if (findPath(arr, x, y + 1, n, solArr)) return true;
    	if (findPath(arr, x - 1, y, n, solArr)) return true;
        if (findPath(arr, x, y - 1, n, solArr)) return true;
        solArr[x][y] = 0;
    }
    return false;
}

int main() {
    int n = 5;

    int QuestionArr[5][5] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int** arr = new int*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = QuestionArr[i][j];
    	}
	}

    int** catArr = new int*[n];
    int** ratArr = new int*[n];
    for (int i = 0; i < n; i++) {
        catArr[i] = new int[n];
        ratArr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            catArr[i][j] = 0;
            ratArr[i][j] = 0;
        }
    }

    findPath(arr, 4, 4, n, catArr);
    findPath(arr, 0, 0, n, ratArr);

    cout << "Cat Path:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << catArr[i][j] << " ";
        }
		cout << endl;
    }

    cout << "\nRat Path:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cout << ratArr[i][j] << " ";
		}
        cout << endl;
    }

    cout << "\nIntersections:\n";
    for (int i = 0; i < n; i++){
	    for (int j = 0; j < n; j++){
            if (ratArr[i][j] == 1 && catArr[i][j] == 1){
                cout << "(" << i << "," << j << ")\n";
        	}
		}    
	}
    return 0;
}

