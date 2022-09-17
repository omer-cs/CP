#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

void printMatrix(vector<vector<int>> arr) {
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
}

void setMatrixZero(vector<vector<int>>& arr) { // Time O(m*n) Space O(m+n)
    int m = arr.size();
    int n = arr[0].size();
    unordered_set<int> rset;
    unordered_set<int> cset;
    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(arr[i][j] == 0) {
                rset.insert(i);
                cset.insert(j);
            }
        }
    }
    for(auto i: rset) {
        cout<<i<<' ';
    }
    cout<<endl;
    for(auto i: cset) {
        cout<<i<<' ';
    }
    cout<<endl;

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(rset.find(i) != rset.end() || cset.find(j) != cset.end()) {
                arr[i][j] = 0;
            }
        }
    }
}

void setMatrixZeroOptimal(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();
    bool row=false;
    bool col=false;

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            if(arr[i][j] ==0) {
                if(i==0) row = true;
                if(j==0) col = true;
                arr[0][j] = arr[i][0] = 0;
            }
        }
    }
    for(int i=1; i<m; ++i) {
        for(int j=1; j<n; ++j) {
            if(arr[0][j] == 0 || arr[i][0]== 0)
                arr[i][j] = 0;
        }
    }
    if(row) {
        for(int j=0; j<n; ++j)
            arr[0][j] = 0;
    }
    if(col) {
        for(int i=0; i<m; ++i)
            arr[i][0] = 0;
    }
    
}


int main() {
    int m, n;
    cin>>m>>n;
    vector<vector<int>> arr(m, vector<int>(n));

    for(int i=0; i<m; ++i) {
        for(int j=0; j<n; ++j) {
            cin>>arr[i][j];
        }
    }

    setMatrixZeroOptimal(arr);

    printMatrix(arr);

    return 0;
}