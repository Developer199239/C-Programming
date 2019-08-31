
public class Print_All_Substrings_n_3 {

	public static void printSubString(String str) {
		int n = str.length();
		
		for(int i = 0; i<n; i++) {
			for(int j = i+1; j<=n; j++) {
				int startPoint = i;
				int endPoint = j;
				for(int k = i; k<j; k++) {
					System.out.print(str.charAt(k));
				}
				System.out.println();
			}	
		}
		
	}
	
	public static void main(String[] args) {
		String str = "abc";
		printSubString(str);
	}

}
