#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}
    };
    priority_queue<node, vector<node>, greater<node>> pq;
    bool visited[1005][1005] = {false};

    pq.push({matrix[0][0], {0, 0}});

    visited[0][0] = true;

    int count = 7;

    while (!pq.empty() && count > 1) {
        node current = pq.top();
        pq.pop(); 
        count--;
        int x = current.second.first;
        int y = current.second.second;
        if (x + 1 < matrix.size() && !visited[x + 1][y]) {
            pq.push({matrix[x + 1][y], {x + 1, y}});
            visited[x + 1][y] = true;
        }
        if (y + 1 < matrix[x].size() && !visited[x][y + 1]) {
            pq.push({matrix[x][y + 1], {x, y + 1}});
            visited[x][y + 1] = true;
        }
    }

    cout << pq.top().first;
    return 0;
}
