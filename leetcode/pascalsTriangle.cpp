#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<vector<int>> pascalsTriangle(int n) {
    vector<vector<int>> result;
    result.push_back({1});
    if(n==1)
        return result;
    result.push_back({1,1});
    if(n==2)
        return result;
    for(int i=2; i<n; ++i) {
        vector<int> temp(i+1);
        temp[0] = 1;
        for(int j=1; j<i; ++j) {
            temp[j] = result[i-1][j-1] + result[i-1][j];
        }
        temp[i] = 1;
        result.push_back(temp);
    }
    return result;
}

int main() {
    int n;
    cin>>n;

    vector<vector<int>> result;
    result = pascalsTriangle(n);

    for(auto i: result) {
        for(auto j: i) {
            cout<<j<<' ';
        }
        cout<<endl;
    }

    return 0;
}