package main

import "fmt"

func factorial(num int) int {
	if num == 0 || num == 1 {
		return 1
	}
	return num * factorial(num-1)
}

func main() {

	var num int

	fmt.Print("Enter the  number : ")
	fmt.Scanln(&num)
	fmt.Print("Factorial of given number : ")
	fmt.Print(factorial(num))

}
