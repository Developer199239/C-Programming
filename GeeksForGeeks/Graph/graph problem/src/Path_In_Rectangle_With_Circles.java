import java.util.Arrays;
import java.util.LinkedList;

import javafx.util.Pair;

public class Path_In_Rectangle_With_Circles {

	int row, col;

	Path_In_Rectangle_With_Circles(int n, int m) {
		this.row = n;
		this.col = m;
	}

	void fillWithCircle(int rect[][], int x, int y, int r) {
		rect[x][y] = -1;
		// top left corner
		int tempx = x, tempy = y;
		for (int i = 0; i < r - 1; i++) {
			if (tempx - 1 >= 0 && tempy - 1 >= 0) {
				tempx--;
				tempy--;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// top right corner
		tempx = x;
		tempy = y;
		for (int i = 0; i < r - 1; i++) {
			if (tempx - 1 >= 0 && tempy + 1 <= col - 1) {
				tempx--;
				tempy++;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// bottom left corner
		tempx = x;
		tempy = y;
		for (int i = 0; i < r - 1; i++) {
			if (tempx + 1 >= row && tempy - 1 >= 0) {
				tempx++;
				tempy--;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// bottom right corner
		tempx = x;
		tempy = y;
		for (int i = 0; i < r - 1; i++) {
			if (tempx + 1 <= row - 1 && tempy + 1 <= col) {
				tempx++;
				tempy++;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// top
		tempx = x;
		tempy = y;
		for (int i = 0; i < r; i++) {
			if (tempx - 1 >= 0) {
				tempx--;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// right
		tempx = x;
		tempy = y;
		for (int i = 0; i < r; i++) {
			if (tempy + 1 <= col - 1) {
				tempy++;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// bottom
		tempx = x;
		tempy = y;
		for (int i = 0; i < r; i++) {
			if (tempx + 1 <= row - 1) {
				tempx++;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		// left
		tempx = x;
		tempy = y;
		for (int i = 0; i < r; i++) {
			if (tempy - 1 >= 0) {
				tempy--;
				rect[tempx][tempy] = -1;
			} else {
				break;
			}
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				System.out.print("rect[" + i + "][" + j + "] = " + rect[i][j] + " ");
			}
			System.out.println();
		}

	}

	boolean bfse(int rect[][]) {
		if (rect[0][0] == -1) {
			return false;
		}

		LinkedList<Pair<Integer, Integer>> qu = new LinkedList<Pair<Integer, Integer>>();
		rect[0][0] = 1;
		qu.add(new Pair<Integer, Integer>(0, 0));

		while (!qu.isEmpty()) {
			Pair<Integer, Integer> pair = qu.poll();
			int elex = pair.getKey();
			int eley = pair.getValue();

			// check top-left cell
			if ((elex > 0) && (eley > 0) && (rect[elex - 1][eley - 1] == 0)) {
				rect[elex - 1][eley - 1] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex - 1, eley - 1);
				qu.add(p);
			}

			// check top cell
			if ((elex > 0) && (rect[elex - 1][eley] == 0)) {
				rect[elex - 1][eley] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex - 1, eley);
				qu.add(p);
			}

			// check top-right cell
			if ((elex > 0) && (eley < col - 1) && (rect[elex - 1][eley + 1] == 0)) {
				rect[elex - 1][eley + 1] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex - 1, eley + 1);
				qu.add(p);
			}

			// check left cell
			if ((eley > 0) && (rect[elex][eley - 1] == 0)) {
				rect[elex][eley - 1] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex, eley - 1);
				qu.add(p);
			}

			// check right cell
			if ((eley > col - 1) && (rect[elex][eley + 1] == 0)) {
				rect[elex][eley + 1] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex, eley + 1);
				qu.add(p);
			}

			// check bottom cell
			if ((elex < row - 1) && (rect[elex + 1][eley] == 0)) {
				rect[elex + 1][eley] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex + 1, eley);
				qu.add(p);
			}

			// check bottom-right cell
			if ((elex < row - 1) && (eley < col - 1) && (rect[elex + 1][eley + 1] == 0)) {
				rect[elex + 1][eley + 1] = 1;
				Pair<Integer, Integer> p = new Pair<Integer, Integer>(elex + 1, eley + 1);
				qu.add(p);
			}
		}

		return (rect[row - 1][col - 1] == 1);
	}

	public static void main(String[] args) {
		int n = 5, m = 5;

		Path_In_Rectangle_With_Circles graph = new Path_In_Rectangle_With_Circles(n, m);

		int[][] rect = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				rect[i][j] = 0;
			}
		}

		int r = 1;
		int x = 1, y = 3;
		graph.fillWithCircle(rect, x, y, r);

		x = 3;
		y = 3;
		graph.fillWithCircle(rect, x, y, r);

		if (graph.bfse(rect)) {
			System.out.print("Possible");
		} else {
			System.out.print("Not Possible");
		}
	}

}
