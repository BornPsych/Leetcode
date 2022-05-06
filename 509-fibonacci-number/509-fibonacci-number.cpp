class Solution {
public:
    int a[600]={0};
    int fib(int n) {
        if(n==1)return 1;
        else if(n<=0)return 0;
        if(a[n]==0)a[n] = fib(n-2) + fib(n-1);
        return a[n];
    }
};