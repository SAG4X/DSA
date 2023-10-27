def dfs(graph: Map[Int, List[Int]], node: Int): List[Int] = {
  def visit(n: Int, visited: Set[Int]): List[Int] =
    if (visited(n)) List()
    else n :: dfs(graph, n, visited + n)

  def dfs(graph: Map[Int, List[Int]], node: Int, visited: Set[Int]): List[Int] =
    graph(node).foldLeft(List(node))((acc, n) => acc ::: visit(n, visited))

  visit(node, Set())
}
