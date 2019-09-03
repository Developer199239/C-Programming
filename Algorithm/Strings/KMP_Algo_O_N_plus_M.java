//understanding 
	//https://www.youtube.com/watch?v=D6dCOa_gMoY&t=1692s
//code
	//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/


public class KMP_Algo_O_N_plus_M {

	public static void kmpSearch(String txt,String pat) {
		int m = pat.length();
		int n = txt.length();
		
		int lps[] = new int[m];
		int j = 0;
		
		computeLPSArray(pat,m,lps);
		
		int matchCount = 0;
		for (int i = 0; i <n; i++) {
			if(txt.charAt(i) == pat.charAt(j)) {
				j++;
				if(j == m) {
					matchCount++;
					System.out.println("Found at index: "+(i-j+1));
					j = lps[j-1];
				}
			} else if(j !=0){
				j = lps[j-1];
				
				while(j>0) {
					if(txt.charAt(i) == pat.charAt(j)) {
						j++;
						if(j == m) {
							matchCount++;
							System.out.println("Found at index: "+(i-j+1));
							j = lps[j-1];
						}
						break;
					} else {
						j = lps[j-1];
					}
				}
			}
		}
		System.out.println("Total match found: "+matchCount);
		
	}
	
	
	//here LPS = longest prefix and suffix
	public static void computeLPSArray(String pat,int size,int lps[]) {
		int len = 0;
		lps[0] = len;
	
		for (int i = 1; i < size; i++) {
			if(pat.charAt(len) == pat.charAt(i)) {
				len++;
				lps[i] = len;
			} else {
				while(len>0) {
					len = lps[len-1];
					if(pat.charAt(len) == pat.charAt(i)) {
						len++;
						lps[i] = len;
						break;
					} else {
						len--;
					}
				}
				if(len<=0) {
					lps[i] = 0;
					len = 0;
				}
			}
		}
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String txt = "ABABDABACDABABCABAB";
		String pat = "ABABCABAB";
		
		kmpSearch(txt, pat);

	}

}
