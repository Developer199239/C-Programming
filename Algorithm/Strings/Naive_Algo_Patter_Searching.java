
public class Naive_Algo_Patter_Searching {

	
	public static void search(String text, String pattern) {
		
		int textLen = text.length();
		int patternLen = pattern.length();
		
		for (int i = 0; i <=textLen - patternLen; i++) {
			boolean flag = true;
			for (int j = 0; j < patternLen; j++) {
				if(text.charAt(i+j) != pattern.charAt(j)) {
					flag = false;
					break;
				}
			}
			if(flag) {
				System.out.println("Pattern found : "+i);
			}
			
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String text = "AABAACAADAABAAABAA";
		String pat = "AABA";
		search(text, pat);

	}

}
