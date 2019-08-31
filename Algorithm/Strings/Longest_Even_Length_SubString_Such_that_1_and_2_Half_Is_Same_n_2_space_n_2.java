
public class Longest_Even_Length_SubString_Such_that_1_and_2_Half_Is_Same_n_2_space_n_2 {

	
	public static void evenLength(String str) {
		int n = str.length();
		int maxlen = 0;
		int startIndex = 0;
		
		int sum[][] = new int[n][n];
		
		for(int i = 0; i<n; i++) {
			sum[i][i] = str.charAt(i) - '0';
		}
		
		
		for(int len = 2; len<=n; len++) {
			for(int i = 0; i<n-len+1; i++) {
				int j = len+i-1;
				int k = len/2;
				sum[i][j] = sum[i][j-k] + sum[j-k+1][j];
				
				if(len % 2 == 0 && sum[i][j-k] == sum[j-k+1][j] && maxlen < len) {
					maxlen  = len;
					startIndex = i;
				}
				
			}
		}
		
		System.out.println("Length of the substring is: "+maxlen);
		System.out.println("Start Index : "+startIndex);
		
		String subSt = str.substring(startIndex, startIndex+maxlen);
		System.out.println("Max SubString : "+subSt);
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "153803";
		evenLength(str);
	}
	
}
