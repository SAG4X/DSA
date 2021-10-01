package main
 
import "fmt"
// Linear search implementation
func linearsearch(datalist []int, key int) bool {
	for _, item := range datalist {
		if item == key {
			return true
		}
	}
	return false
} 

// Main Function
func main() {
    items := []int{95,78,46,58,45,86,99,251,320}
    if linearsearch(items,58){
	fmt.Println("Search is success")
    } else {
	fmt.Println("Search is unsuccess")
    }	
    
}
