import java.util.Iterator;
import java.util.LinkedList;

public class Count_Number_Nodes_Given_Level_In_Tree {

	private int vertices;
	private LinkedList<Integer> adj[];

	public Count_Number_Nodes_Given_Level_In_Tree(int ver) {
		this.vertices = ver;
		adj = new LinkedList[ver];
		for (int i = 0; i < ver; i++) {
			adj[i] = new LinkedList();
		}

	}

	void addEdge(int v, int u) {
		adj[v].add(u);
		adj[u].add(v);
	}

	void BFS(int source, int levels[]) {
		boolean visited[] = new boolean[vertices];
		LinkedList<Integer> queue = new LinkedList<Integer>();

		levels[source] = 0;
		visited[source] = true;
		queue.add(source);

		while (!queue.isEmpty()) {
			int parentNode = queue.poll();

			Iterator<Integer> iterator = adj[parentNode].listIterator();

			while (iterator.hasNext()) {
				int node = iterator.next();
				if (visited[node] == false) {
					levels[node] = levels[parentNode] + 1;
					queue.add(node);
					visited[node] = true;
				}
			}

		}

	}

	public static void main(String[] args) {
		int vertices = 6;
		Count_Number_Nodes_Given_Level_In_Tree g = new Count_Number_Nodes_Given_Level_In_Tree(vertices);

		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 3);
		g.addEdge(2, 4);
		g.addEdge(2, 5);

		int levels[] = new int[vertices];

		g.BFS(0, levels);

		int level = 2;

		int cnt = 0;
		for (int i = 0; i < vertices; i++) {
			if (levels[i] == level) {
				cnt++;
			}
		}

		System.out.print("Level " + level + " has child " + cnt);

	}

}
