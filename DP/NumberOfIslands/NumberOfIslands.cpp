#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int row, col;

int rowPath[] = {-1, 0, 0, 1};

int colPath[] = {0, -1, 1, 0};

bool isPath(int i, int j) {
    if(i < 0)
        return false;
    if(j < 0)
        return false;
    if(i >= row)
        return false;
    if(j >= col)
        return false;
    return true;
}

void dfs(const vector< vector<int> >& mat, int i, int j, vector< vector<bool> >& visited) {
    visited[i][j] = true;
    for(int k = 0; k < 4; k++) {
        int x = i + rowPath[k];
        int y = j + colPath[k];
        if(isPath(x, y) && mat[x][y] && !visited[x][y]) {
            dfs(mat, i+rowPath[k], j+colPath[k], visited);
        }
    }
}

int main() {
    cout << "\nEnter row: ";
    cin >> row;
    cout << "\nEnter column: ";
    cin >> col;
    vector< vector<int> > mat(row, vector<int> (col, 0));
    vector< vector<bool> > visited(row, vector<bool> (col, false));
    string temp;
    cout << "\nEnter map: ";
    for(int i = 0; i < row; i++) {
        cin >> temp;
        for(int j = 0; j < col; j++) {
            mat[i][j] = temp[j] - '0';
            visited[i][j] = false;
        }
    }
    int count = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(!visited[i][j] && mat[i][j]) {
                dfs(mat, i, j, visited);
                count++;   
            }
        }
    }
    cout << "\nThere are " << count << " islands in the map";
    return 0;
}