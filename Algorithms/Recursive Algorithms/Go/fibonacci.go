// Golang program to
// print the Fibonacci series using recursion

package main

import "fmt"

func printFibonacii(a int, b int, n int) {
	var sum int = 0
	if n > 0 {
		sum = a + b
		fmt.Printf("%d ", sum)
		a = b
		b = sum
		printFibonacii(a, b, n-1)
	}
}

func main() {
	var a, b, n int

	a = 0
	b = 1

	fmt.Printf("Enter total number of terms: ")
	fmt.Scanf("%d", &n)

	fmt.Printf("Fibonacii series is : ")
	fmt.Printf("%d\t%d ", a, b)

	printFibonacii(a, b, n-2)
	fmt.Printf("\n")
}