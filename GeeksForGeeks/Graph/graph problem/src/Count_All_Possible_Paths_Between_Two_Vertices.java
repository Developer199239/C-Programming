import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;


//https://www.geeksforgeeks.org/count-possible-paths-two-vertices/
public class Count_All_Possible_Paths_Between_Two_Vertices {
	private int vertices;
	private LinkedList<Integer> adj[];

	Count_All_Possible_Paths_Between_Two_Vertices(int ver) {
		vertices = ver;
		adj = new LinkedList[ver];

		for (int i = 0; i < ver; i++) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	void addEdge(int v, int w) {
		adj[v].add(w);
	}
	
	int countPaths(int u, int d, boolean visited[], int pathCount) {
		visited[u] = true;
		
		if(u == d) {
			pathCount++;
		} else {
			Iterator<Integer> iterator = adj[u].listIterator();
		
			while(iterator.hasNext()) {
				int n = iterator.next();
				
				if(visited[n] == false) {
					pathCount = countPaths(n, d, visited, pathCount);
				}
			}
		}
	
		// this is false bcz we reach destination for again calculate destination then set false
		visited[u] = false;
		return pathCount;
		
	}
	
	int countPath() {
		  
        int source = 2, destination = 3;
        
        boolean visited[] = new boolean[vertices];
        Arrays.fill(visited, false);
        int pathCount = 0;
        pathCount = countPaths(source,destination,visited,pathCount);
        
        return pathCount;
        
	}

	public static void main(String[] args) {

		Count_All_Possible_Paths_Between_Two_Vertices g = new Count_All_Possible_Paths_Between_Two_Vertices(4);
		g.addEdge(0, 1); 
        g.addEdge(0, 2); 
        g.addEdge(0, 3); 
        g.addEdge(2, 0); 
        g.addEdge(2, 1); 
        g.addEdge(1, 3); 
        
		System.out.println(g.countPath());
		
	}

}
