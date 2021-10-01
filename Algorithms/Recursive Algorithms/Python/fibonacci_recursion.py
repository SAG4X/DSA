# recursion
def fibo_recursion(n):
    if(n == 0):
        return 0
    if(n == 1):
        return 1
    else:
        return fibo_recursion(n-2) + fibo_recursion(n-1);

# Base method
print("---------Fibonaaci sequence------------\n")
# Define the n
n = 10
for i in range(n):
    print(fibo_recursion(i))
