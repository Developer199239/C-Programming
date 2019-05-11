import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class Count_Number_of_trees_in_a_forest {

	int vertices;
	LinkedList<Integer> adj[];

	Count_Number_of_trees_in_a_forest(int v) {
		vertices = v;
		adj = new LinkedList[v];
		for (int i = 0; i < v; i++) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	void addEdge(int u, int v) {
		adj[u].add(v);
		adj[v].add(u);
	}

	void DFS(int sourceNode, boolean visited[]) {
		visited[sourceNode] = true;

		Iterator<Integer> list = adj[sourceNode].listIterator();

		while (list.hasNext()) {
			int n = list.next();
			if (visited[n] == false) {
				DFS(n, visited);
			}
		}
	}

	int countTree() {
		int res = 0;

		boolean visited[] = new boolean[vertices];
		Arrays.fill(visited, false);

		for (int i = 0; i < vertices; i++) {
			if (visited[i] == false) {
				res++;
				DFS(i,visited);
			}
		}

		return res;
	}

	public static void main(String[] args) {
		int v = 5;
		Count_Number_of_trees_in_a_forest graph = new Count_Number_of_trees_in_a_forest(v);

		graph.addEdge(0, 1);
		graph.addEdge(0, 2);
		graph.addEdge(0, 4);
		
		System.out.println("Number of tree is : "+graph.countTree());

	}

}
