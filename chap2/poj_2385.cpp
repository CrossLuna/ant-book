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
    int T, W;
    cin >> T >> W;
    vector<int> arr(T+1, 0);
    for(int i=1; i<=T; ++i) {
        cin >> arr[i];
        arr[i] -= 1;
    }
    //Tree: 0 or 1

    vector<vector<int> > dp(T+1, vector<int>(W+1, 0));

    for(int i=1; i<=T; ++i) {
        dp[i][0] = dp[i-1][0];
        if(arr[i] == 0) {
            dp[i][0] += 1;
        }
    }

    for(int j=1; j<=W; ++j) {
        for(int i=j; i<=T; ++i) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]);
            if(j%2 == arr[i]) {
                dp[i][j] += 1;
            }
        }
    }
    cout << dp.back().back() << endl;
}