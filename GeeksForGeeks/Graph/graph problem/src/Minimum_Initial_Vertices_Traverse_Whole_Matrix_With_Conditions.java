import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;

import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils.Collections;

import javafx.util.Pair;
import sun.net.www.content.audio.x_aiff;

//https://www.geeksforgeeks.org/minimum-initial-vertices-traverse-whole-matrix-given-conditions/
public class Minimum_Initial_Vertices_Traverse_Whole_Matrix_With_Conditions {

	public static int MAX = 100;

	Minimum_Initial_Vertices_Traverse_Whole_Matrix_With_Conditions() {

	}

	/**
	 * n,m is current source cell from which we need to do DFS.
	 */
	void dfs(int n, int m, boolean[][] visited, int adj[][], int row, int col) {
		visited[n][m] = true;

		// if below neighbor is valid
		if (n + 1 < row && adj[n][m] >= adj[n + 1][m] && visited[n + 1][m] == false) {
			dfs(n + 1, m, visited, adj, row, col);
		}

		// if right neighbor is valid
		if (m + 1 < col && adj[n][m] >= adj[n][m + 1] && visited[n][m + 1] == false) {
			dfs(n, m + 1, visited, adj, row, col);
		}

		// if above neighbor is valid
		if (n - 1 >= 0 && adj[n][m] == adj[n - 1][m] && visited[n - 1][m] == false) {
			dfs(n - 1, m, visited, adj, row, col);
		}

		// if left neighbor is valid
		if (m - 1 >= 0 && adj[n][m] >= adj[n][m - 1] && visited[n][m - 1] == false) {
			dfs(n, m - 1, visited, adj, row, col);
		}

	}

	void printMinSource(int adj[][], int row, int col) {
		LinkedList<Pair<Integer, Pair<Integer, Integer>>> list = new LinkedList();
		boolean visited[][] = new boolean[row][col];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				visited[i][j] = false;
				list.add(new Pair<Integer, Pair<Integer, Integer>>(adj[i][j], new Pair<Integer, Integer>(i, j)));
			}
		}

		// here sort list
		list.sort(new Comparator<Pair<Integer, Pair<Integer, Integer>>>() {
			@Override
			public int compare(Pair<Integer, Pair<Integer, Integer>> o1, Pair<Integer, Pair<Integer, Integer>> o2) {
				return o1.getKey().compareTo(o2.getKey());
			}
		});

//		for (int i = 0; i < list.size(); i++) {
//			System.out.println("value is" + list.get(i).getKey());
//		}

		// Applying dfs for each vertex with highest value
		for (int i = list.size()-1; i >= 0; i--) {
			int x = list.get(i).getValue().getKey();
			int y = list.get(i).getValue().getValue();

			if (visited[x][y] == false) {
				System.out.println("Point is (" + x + " " + y + ")");
				dfs(x, y, visited, adj, row, col);
			}
		}

	}

	public static void main(String[] args) {
		int row = 3, col = 3;
		int adj[][] = { { 1, 2, 3 }, { 2, 3, 1 },{1,1,1} };

		Minimum_Initial_Vertices_Traverse_Whole_Matrix_With_Conditions graph = new Minimum_Initial_Vertices_Traverse_Whole_Matrix_With_Conditions();
		graph.printMinSource(adj, row, col);

	}

}
