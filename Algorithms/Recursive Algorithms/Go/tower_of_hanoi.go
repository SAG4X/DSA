package main

import (
	"fmt"
	"strconv"
)

func TOH_moves(num int, start, inter, end string) {
	if num == 1 {
		fmt.Println("Move disk 1 from " + start + " to " + end)
		return
	}
	TOH_moves(num-1, start, end, inter)
	fmt.Println("Move disk " + strconv.Itoa(num) + " from " + start + " to " + end) //strconv.Itoa() used for type casting int to string
	TOH_moves(num-1, inter, end, start)

}

func main() {

	var num int

	fmt.Print("Enter the  number of disk : ")
	fmt.Scanln(&num)
	TOH_moves(num, "A", "B", "C")
}
