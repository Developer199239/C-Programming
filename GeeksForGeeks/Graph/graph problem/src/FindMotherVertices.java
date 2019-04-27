import java.util.Iterator;
import java.util.LinkedList;

public class FindMotherVertices {

	private int vertices;
	private LinkedList<Integer> adj[];

	FindMotherVertices(int v) {
		vertices = v;
		adj = new LinkedList[v];
		for (int i = 0; i < v; i++) {
			adj[i] = new LinkedList();
		}
	}

	void addEdge(int v, int u) {
		adj[v].add(u);
	}

	void DFS(int v, boolean visited[]) {
		visited[v] = true;

		Iterator<Integer> iterator = adj[v].listIterator();
		while (iterator.hasNext()) {
			int node = iterator.next();
			if (visited[node] == false) {
				DFS(node, visited);
			}
		}
	}

	int findMotherNode() {
		boolean visited[] = new boolean[vertices];

		int v = -1;

		// The vertex that finishes last should be the mother node
		for (int i = 0; i < vertices; i++) {
			if (visited[i] == false) {
				DFS(i, visited);
				v = i;
			}
		}

		// the node that finishes last in DFS can be the mother vertex
		for (int i = 0; i < vertices; i++) {
			visited[i] = false;
		}

		// we found the last finishing node
		// need to validate that
		// consider a individual node in the graph. It may not be last vertex to finish.
		// to we need to confirm that
		DFS(v, visited);

		for (int i = 0; i < vertices; i++) {
			if (visited[i] == false) {
				return -1;
			}
		}

		return v;
	}

	public static void main(String[] args) {
		FindMotherVertices findMotherVertices = new FindMotherVertices(7);

		findMotherVertices.addEdge(0, 1);
		findMotherVertices.addEdge(0, 2);
		findMotherVertices.addEdge(1, 3);
		findMotherVertices.addEdge(4, 1);
		findMotherVertices.addEdge(6, 4);
		findMotherVertices.addEdge(6, 0);
		findMotherVertices.addEdge(5, 2);
		findMotherVertices.addEdge(5, 6);

		int node = findMotherVertices.findMotherNode();
		if(node == -1) {
			System.out.println("Not a mother vertex");
		} else {
			System.out.println("Mother vertex is "+node);
		}

	}

}
