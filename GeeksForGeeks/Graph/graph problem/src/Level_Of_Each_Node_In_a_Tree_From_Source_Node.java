import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class Level_Of_Each_Node_In_a_Tree_From_Source_Node {

	int vertices;
	LinkedList<Integer> adj[];

	Level_Of_Each_Node_In_a_Tree_From_Source_Node(int ver) {
		vertices = ver;
		adj = new LinkedList[ver];
		for (int i = 0; i < ver; i++) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	void addEdge(int u, int v) {
		adj[u].add(v);
	}

	void BFS(int source) {
		int[] level = new int[vertices];
		Arrays.fill(level, 0);

		boolean visited[] = new boolean[vertices];
		Arrays.fill(visited, false);

		LinkedList<Integer> queue = new LinkedList<Integer>();

		level[source] = 0;
		queue.add(source);
		visited[source] = true;

		while (queue.size() > 0) {
			source = queue.poll();

			Iterator<Integer> list = adj[source].listIterator();
			while (list.hasNext()) {
				int node = list.next();
				if (visited[node] == false) {
					visited[node] = true;
					level[node] = level[source] + 1;
					queue.add(node);
				}
			}

		}
		
		
		for(int i = 0; i<vertices; i++) {
			System.out.println(" "+i+" --> "+level[i]);
		}

	}

	public static void main(String[] args) {
		Level_Of_Each_Node_In_a_Tree_From_Source_Node graph = new Level_Of_Each_Node_In_a_Tree_From_Source_Node(8);

		graph.addEdge(0, 1);
		graph.addEdge(0, 2);
		graph.addEdge(1, 3);
		graph.addEdge(1, 4);
		graph.addEdge(1, 5);
		graph.addEdge(2, 5);
		graph.addEdge(2, 6);
		graph.addEdge(6, 7);

		graph.BFS(0);

	}

}
