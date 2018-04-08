#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
//#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i=0; i<(n); ++i)
#define pb push_back

const int dr [] = {-1, -1,  0,  1,  1,  1,  0, -1};
const int dc [] = {0 ,  1,  1,  1,  0, -1, -1, -1};
// (-1, 0) (-1, 1) (0, 1) (1, 1) (1, 0) (1, -1) (0, -1) (-1, -1)
// from left, clockwise

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    //===============
    int N;
    cin >> N;
    vector<int> curr(N, 0);
    vector<int> next(N, 0);
    FOR(n, 1, N+1) {
        //Read lines
        FOR(i, 0, n) {
            cin >> next[i];
        }
        next[0] += curr[0];
        FOR(i, 1, n) {
            next[i] += max(curr[i], curr[i-1]);
        }
        swap(curr, next);
    }

    int ans = -1;
    REP(i, N) {
        ans = max(ans, curr[i]);
    }
    cout << ans << endl;

}