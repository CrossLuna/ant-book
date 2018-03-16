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

using namespace std;

typedef pair<int, int> P;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int H, W;

void dfs(vector<string>& mp, int i, int j, char c) {
    mp[i][j] = '-';
    REP(k, 4) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if(0 <= ni && ni < H && 0 <= nj && nj < W && mp[ni][nj] == c) {
            dfs(mp, ni, nj, c);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    // =============================
    while(cin >> H >> W) {
        int ans = 0;
        if(H == 0 && W == 0) break;
        vector<string> mp;
        REP(i, H) {
            string tmp;
            cin >> tmp;
            mp.pb(tmp);
        }
        REP(i, H) {
            REP(j, W) {
                if(mp[i][j] != '-') {
                    ++ans;
                    dfs(mp, i, j, mp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
}