//https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/
//-- for understanding algo, visit bellow youtube link --
//https://youtu.be/HBtiDHIOK9A
public class Longest_Palindromic_subString_n_2 {

	
	static void printSubStr(String str, int low, int high) {
		System.out.println(str.substring(low,high+1));
	}
	
	static void longestPalSubStr(String str) {
		int n = str.length();
		
		boolean table[][] = new boolean[n][n];
		
		int maxLenght = 1;
		
		for(int i = 0; i<n; i++) {
			table[i][i] = true;
		}
		
		//check for sub-string of length 2.
		int start = 0;
		for(int i = 0; i<n-1; i++) {
			if(str.charAt(i) == str.charAt(i+1)) {
				table[i][i+1] = true;
				start = i;
				maxLenght = 2;
			}
		}
		
		//check for lengths greater than 2. 
		for(int k = 3; k<=n; k++) {
			for(int i = 0; i<n-k+1; i++) {
				int j = i+k-1;
				
				if(table[i+1][j-1] && str.charAt(i) == str.charAt(j)) {
					table[i][j] = true;
					
					if(k > maxLenght) {
						start = i;
						maxLenght = k;
					}
				}
			}
		}
		
		System.out.print("Longest palindrome substring is: ");
		printSubStr(str, start, start+maxLenght-1);
	
		System.out.print("Length is: "+maxLenght);

	}
	
	
	public static void main(String[] args) {
		String str = "gekes";
		longestPalSubStr(str);
	}

}
