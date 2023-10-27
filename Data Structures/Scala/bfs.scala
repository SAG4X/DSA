def bfs(graph: Map[Int, List[Int]], start: Int): List[Int] = {
  var visited = Set.empty[Int]
  var queue = List(start)
  var result = List.empty[Int]

  while (queue.nonEmpty) {
    val node = queue.head
    queue = queue.tail
    if (!visited(node)) {
      visited += node
      result = node :: result
      queue ++= graph(node).filterNot(visited)
    }
  }

  result.reverse
}
