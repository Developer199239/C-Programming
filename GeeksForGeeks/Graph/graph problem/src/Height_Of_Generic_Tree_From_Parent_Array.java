import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import com.sun.corba.se.impl.orbutil.graph.Node;

public class Height_Of_Generic_Tree_From_Parent_Array {

	int n;
	LinkedList<Integer> adj[];
	int rootNode = 0;

	Height_Of_Generic_Tree_From_Parent_Array(int node) {
		this.n = node;
		adj = new LinkedList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	void buildTree(ArrayList<Integer> list) {
		int root_index = 0;

		for (int i = 0; i < list.size(); i++) {
			if (list.get(i) == -1) {
				root_index = i;
			} else {
				adj[i].add(list.get(i));
				adj[list.get(i)].add(i);
			}
		}

		this.rootNode = root_index;
	}

	int bfs() {
		boolean[] visited = new boolean[n];
		Arrays.fill(visited, false);

		int[] levels = new int[n];
		Arrays.fill(levels, 0);

		LinkedList<Integer> queue = new LinkedList<Integer>();
		queue.add(rootNode);
		levels[rootNode] = 0;
		visited[rootNode] = true;
		int maxLevel = 0;
		while (!queue.isEmpty()) {
			int source = queue.poll();

			Iterator<Integer> iterator = adj[source].listIterator();
			while (iterator.hasNext()) {
				int node = iterator.next();
				if (visited[node] == false) {
					queue.add(node);
					visited[node] = true;
					levels[node] = levels[source] + 1;
					maxLevel = Math.max(maxLevel, levels[node]);
				}
			}

		}

		return maxLevel;

	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int node;
		node = scanner.nextInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i = 0; i < node; i++) {
			list.add(scanner.nextInt());
		}

		Height_Of_Generic_Tree_From_Parent_Array graph = new Height_Of_Generic_Tree_From_Parent_Array(node);
		graph.buildTree(list);

		int maxLevle = graph.bfs();
		System.out.println("Max level "+maxLevle);
	}

}
