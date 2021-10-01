package main
import "fmt"

// Binary Search Implementation
func binarySearch(needle int, haystack []int) bool {

	low := 0
	high := len(haystack) - 1

	for low <= high{
		median := (low + high) / 2

		if haystack[median] < needle {
			low = median + 1
		}else{
			high = median - 1
		}
	}

	if low == len(haystack) || haystack[low] != needle {
		return false
	}

	return true
}

// Main Function
func main(){
	items := []int{1,2, 9, 20, 31, 45, 63, 70, 100}
	fmt.Println()
	if binarySearch(63, items){
	    fmt.Println("Search is success")
	} else{
	    fmt.Println("Search is unsuccess")
	}
    		
}
