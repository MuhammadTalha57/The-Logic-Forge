#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N + M)
Space Complexity = O(1)

*/

double solve(vector<int>& scoresA, vector<int>& scoresB) {
    int n = scoresA.size(), m = scoresB.size();
    if(n == 0 && m == 0) return 0;

    int target = (n + m) / 2;

    int pre = -1e9;
    int cur = -1;

    int i = 0, j = 0;
    int k = 0;
    while(i < n && j < m) {
        pre = cur;
        cur = (scoresA[i] <= scoresB[j] ? scoresA[i++]: scoresB[j++]);

        if(k == target) {
            if((n + m) & 1) return cur;
            else return double(cur + pre) / 2.0;
        }
        k++;
        
    }

    while(i < n) {
        pre = cur;
        cur = scoresA[i++];
        if(k == target) {
            if((n + m) & 1) return cur;
            else return double(cur + pre) / 2.0;
        }
        k++;
    }

    while(j < m) {
        pre = cur;
        cur = scoresB[j++];
        if(k == target) {
            if((n + m) & 1) return cur;
            else return double(cur + pre) / 2.0;
        }
        k++;
    }

    return cur;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> scoresA = {1, 2}, scoresB = {3, 4};
    cout << solve(scoresA, scoresB) << '\n';


    return 0;
}