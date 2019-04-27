import java.util.Iterator;
import java.util.LinkedList;

public class DFS {

	private int vertices;
	private LinkedList<Integer>adj[];
	
	DFS(int ver){
		vertices = ver;
		adj = new LinkedList[vertices];
		for(int i = 0; i<vertices; i++) {
			adj[i] = new LinkedList();
		}
	}
	
	void addEdge(int v, int w) {
		adj[v].add(w);
	}
	
	void depthFirstSearch(int v, boolean visited[]) {
		visited[v] = true;
		System.out.print(v+" ");
		
		Iterator<Integer> iterator = adj[v].listIterator();
		while(iterator.hasNext()) {
			int n = iterator.next();
			if(visited[n] == false) {
				depthFirstSearch(n, visited);
			}
		}
	}
	
	
	
	public static void main(String[] args) {
		
		int vertices = 4;
		
		DFS dfs = new DFS(vertices);
		
		dfs.addEdge(0, 1); 
		dfs.addEdge(0, 2); 
		dfs.addEdge(1, 2); 
		dfs.addEdge(2, 0); 
		dfs.addEdge(2, 3); 
		dfs.addEdge(3, 3); 
		
		boolean visited[] = new boolean[vertices];
		dfs.depthFirstSearch(0, visited);
		
	}

}
