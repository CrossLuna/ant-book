# 2.1 暴力搜索 (窮舉法)

## 遞迴

求階乘
```c++
int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n-1);
}
```

求Fibonacci數列
```c++
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```
此種求法的複雜度是指數級別，解決方法是用動態規劃(Dynamic Programming)或是記憶(Memoization)
```c++
int memo[MAX_N+1];
int fib(int n) {
    if(n <= 1) return n;
    if(memo[n] != 0) return memo[n];
    return memo[n] = fib(n-1) + fib(n-2);
}
```