package main

import "fmt"

// simple solution -- substracting smaller number from larger
func GCD1(a, b int) int {
	if a == 0 {
		return b
	}
	if b == 0 {
		return a
	}
	if a == b {
		return a
	}

	if a > b {
		return GCD1(a-b, b)
	} else {
		return GCD1(a, b-a)
	}
}

// Euclidean algorithm
func GCD2(a, b int) int {
	if b == 0 {
		return a
	}
	return GCD2(b, a%b)
}

func main() {

	var first, second int

	fmt.Print("Enter first  number : ")
	fmt.Scanln(&first)
	fmt.Print("Enter second number : ")
	fmt.Scanln(&second)

	fmt.Print("GCD using simple solution : ")
	fmt.Println(GCD1(first, second))
	fmt.Print("GCD using Euclidean Algorithm : ")
	fmt.Println(GCD2(first, second))

}
