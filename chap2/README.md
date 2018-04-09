# 2.1 全搜索

## 深度優先搜索 Depth First Search

### POJ 1979 - Red and Black

基本DFS題，不小心用了BFS...
複雜度O(n)，n = 格子數

### AOJ 0118 - Property Distribution

基本DFS題，每次處理一種水果就行
複雜度O(n)

## 動態規劃 Dynamic Programming

### POJ 3176 - Cow Bowling
基本DP題，可以只用兩個向量處理  
時間複雜度O(n^2)，n = 瓶子的行數
空間複雜度O(n^2)，n = 瓶子數行數，優化過後只用兩個向量，可達O(2n)


### POJ 2229 - Sumsets
### POJ 2385 - Apple Catching
預處理，把蘋果樹轉換成0或1，方便操作  
動態規劃，DP[T][W] 表示T秒時，已轉移W次時可以得到的最多蘋果樹，注意T=1之前也可以轉移  
狀態轉移方程為 DP[i][j] = max(DP[i-1][j-1], DP[i-1][j]) + (tree[i] == j % 2)
DP[i-1][j-1]表示轉移，DP[i-1][j]表示不轉，j % 2 表示所在的蘋果樹下
時間空間複雜度O(T*W)

### POJ 3616
### POJ 3280