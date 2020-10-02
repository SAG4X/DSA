#recursive:
def fib_rec(n):
    if(n == 1 or n == 2):
        return 1
    if (memo[n] != 0):
        return memo[n]
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n]

#iterative:
def fib_it(n):
    memo[1] = memo[2] = 1
    for i in range(3,n):
        memo[i] = memo[i-1] +memo[i-2]
    return memo[n-1]
   

x=int(input())
memo=[0]*100000000

#print(fib_it(x))
print(fib_it(x))
