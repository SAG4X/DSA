def quickSort(arr: Array[Int]): Array[Int] = {
  if (arr.length <= 1) arr
  else {
    val pivot = arr(arr.length / 2)
    val (left, right) = arr.partition(_ < pivot)
    quickSort(left) ++ arr.filter(_ == pivot) ++ quickSort(right)
  }
}
