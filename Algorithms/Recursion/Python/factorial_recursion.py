# recursion
def factorial_recursion(n):
    # Base case
    if(n == 0):
        return 1
    # Recursive case
    else:
        return n*factorial_recursion(n-1);

# Base method
print("---------Fibonaaci sequence------------\n")
# Define the n
n = 10
for i in range(n):
    print('Factorial '+str(i)+': is = '+str(factorial_recursion(i)))
