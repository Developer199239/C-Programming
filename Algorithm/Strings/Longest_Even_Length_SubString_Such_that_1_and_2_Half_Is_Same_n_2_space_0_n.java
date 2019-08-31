
public class Longest_Even_Length_SubString_Such_that_1_and_2_Half_Is_Same_n_2_space_0_n {

	public static void evenSubStringLenght(String str) {
		int n = str.length();
		int sum[] = new int[n+1];
		sum[0] = 0;
		//store cumulative sum of digits
		for(int i = 0; i<n; i++) {
			sum[i+1] = sum[i] + str.charAt(i) - '0';
		}
		
		int ans = 0;
		for(int len = 2; len<=n; len = len + 2) {
			for(int i = 0; i<=n-len; i++) {
				//rules:
					//1. sum[i+len/2] - sum[i] == sum[i+len] - sum[i+len/2]
				if((sum[i+len/2] - sum[i]) == (sum[i+len] - sum[i+len/2])) {
					ans = Math.max(ans, len);
				}
			}
		}
		
		System.out.println("Max lenght is: "+ans);
		
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String string = "123123";
		evenSubStringLenght(string);

	}

}
