##The permutation coefficient for a mathematical sum is given by:
##
##        P(n,k)= n*(n-1)*(n-2)*........*(n-k+1)
##
##        which is 0 when k>n, and otherwise equal to:
##            n!/(n-k!)

##Dynamic programming solution
def permutationCoeff(n, k): 
  
    memo = [[0 for i in range(k + 1)]  
            for j in range(n + 1)]  
    # bottom up manner 
    for i in range(n + 1): 
        for j in range(min(i, k) + 1): 
  
            # Base case 
            if (j == 0): 
                memo[i][j] = 1
  
            # get meomixed data
            else: 
                memo[i][j] = memo[i - 1][j] + (j * memo[i - 1][j - 1]) 
  
            #memo(i, j)=0for j>i 
            if (j < k): 
                memo[i][j + 1] = 0
    return memo[n][k]


n=int(input("Enter value for n: "))
k=int(input("Enter value for k: "))

print("P(", n, ", ", k, ") =", 
       permutationCoeff(n, k), sep = "")
            
