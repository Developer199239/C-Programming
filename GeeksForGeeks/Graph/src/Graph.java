import java.util.Iterator;
import java.util.LinkedList;

public class Graph {

	private int vertices;
	private LinkedList<Integer> adj[];
	
	public Graph(int vertices) {
		this.vertices = vertices;
		adj = new LinkedList[vertices];
		
		for(int i = 0; i<vertices; i++) {
			adj[i] = new LinkedList();
		}
	}
	
	void addEdge(int v, int w) {
		adj[v].add(w);
	}
	
	void BFS(int source) {
		boolean visited[] = new boolean[vertices];
		
		LinkedList<Integer> queue = new LinkedList<Integer>();
		
		visited[source] = true;
		queue.add(source);
		
		while(queue.size() != 0) {
			source = queue.poll();
			System.out.print(source+" ");
			
			Iterator<Integer> iterator = adj[source].listIterator();
			while(iterator.hasNext()) {
				int n = iterator.next();
				if(!visited[n]) {
					visited[n] = true;
					queue.add(n);
				}
			}	
		}
	}
	
	
	
	public static void main(String[] args) {
		Graph graph = new Graph(4);
		
		graph.addEdge(0, 1); 
		graph.addEdge(0, 2); 
		graph.addEdge(1, 2); 
		graph.addEdge(2, 0); 
		graph.addEdge(2, 3); 
		graph.addEdge(3, 3); 
		
		graph.BFS(0);

	}

}
