package main
import "fmt"

// Function Implemntation
func BubbleSort(array[] int)[]int {
   for i:=0; i< len(array)-1; i++ {
      for j:=0; j < len(array)-i-1; j++ {
         if (array[j] > array[j+1]) {
	   // swap values
            array[j], array[j+1] = array[j+1], array[j]
         }
      }
   }
   return array
}
func main() {
   array:= []int{11, 14, 3, 8, 18, 17, 43};
   // Before sorting
   fmt.Println("Before Sorting: ");
   fmt.Println(array);
   // Bubble sort function call
   // sorted
   fmt.Println("Sorted Array: ");
   fmt.Println(BubbleSort(array))
}
