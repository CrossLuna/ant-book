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

int main() {
    std::ios::sync_with_stdio(false);
    //===============
    int W, H;
    while(true) {
        int ans = 1;
        cin >> W >> H;
        if (W == 0 && H == 0) break;
        vector<string> mmap;
        int x = -1;
        int y = -1;
        REP(i, H) {
            string s;
            cin >> s;
            FOR(j, 0, W) {
                if(s[j] == '@') {
                    x = i;
                    y = j;
                }
            }
            mmap.pb(s);
        }
        
        queue<P> que;
        que.push(P(x, y));
        while(que.size()) {
            P p = que.front();
            //cout << "P: " << p.first << " , " << p.second << endl;
            que.pop();
            if(mmap[p.first][p.second] == '.') {
                mmap[p.first][p.second] = '@';
                ++ans;
            }
            REP(i, 4) {
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if(0 <= nx && nx < H && 0 <= ny && ny < W && mmap[nx][ny] == '.') {
                    que.push(P(nx, ny));
                }
            }
        }
        cout << ans << endl;
    }
}