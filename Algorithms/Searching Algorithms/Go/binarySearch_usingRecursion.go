package main

import "fmt"

// Recursive Binary Search Implementation
func binarySearch(search int, startIndex int, endIndex int, array []int) int {

	// starting index should be less than or equal to end index
	if startIndex <= endIndex {

		// getting the middle element of subarray
		middle := (startIndex + endIndex) / 2

		// check if middle element is the searching element or not
		// if middle element is greater than the searching element then search in left-
		// -side of middle element or else search in right side of middle elements
		if array[middle] == search {
			return middle
		} else if array[middle] > search {
			return binarySearch(search, startIndex, middle-1, array)
		} else {
			return binarySearch(search, middle+1, endIndex, array)
		}

	}

	// return -1 if element not found
	return -1
}

// Main Function
func main() {

	// array should be sorted for binary search
	array := []int{1, 2, 9, 20, 31, 45, 63, 70, 100}
	fmt.Println()

	var res = binarySearch(63, 0, 8, array)

	if res != -1 {
		fmt.Print("Element found at index : ")
		fmt.Println(res)
	} else {
		fmt.Println("Element not found")
	}

}
