def mergeSort(arr: List[Int]): List[Int] = {
  def merge(left: List[Int], right: List[Int]): List[Int] = (left, right) match {
    case (Nil, _) => right
    case (_, Nil) => left
    case (lh :: lt, rh :: rt) =>
      if (lh < rh) lh :: merge(lt, right)
      else rh :: merge(left, rt)
  }

  val n = arr.length / 2
  if (n == 0) arr
  else {
    val (left, right) = arr.splitAt(n)
    merge(mergeSort(left), mergeSort(right))
  }
}
