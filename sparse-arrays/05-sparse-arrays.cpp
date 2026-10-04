#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
    unordered_map<string, int> frequency;

    for (string s : strings) {
        frequency[s]++;
    }

    vector<int> result;

    for (string q : queries) {
        result.push_back(frequency[q]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int q;
    cin >> q;

    vector<string> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<int> result = matchingStrings(strings, queries);

    for (int x : result) {
        cout << x << endl;
    }

    return 0;
}