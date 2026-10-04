#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> seqList(n);
    vector<int> result;
    int lastAnswer = 0;

    for (auto query : queries) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        int index = (x ^ lastAnswer) % n;

        if (type == 1) {
            seqList[index].push_back(y);
        } 
        else if (type == 2) {
            lastAnswer = seqList[index][y % seqList[index].size()];
            result.push_back(lastAnswer);
        }
    }

    return result;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> answers = dynamicArray(n, queries);

    for (int answer : answers) {
        cout << answer << endl;
    }

    return 0;
}