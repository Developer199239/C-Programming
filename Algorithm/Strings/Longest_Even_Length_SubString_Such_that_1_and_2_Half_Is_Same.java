
public class Longest_Even_Length_SubString_Such_that_1_and_2_Half_Is_Same {

	
	public static void longestEvenLength(String str) {
		int len = str.length();
		
		int maxLen = 0;
		
		for(int i = 0; i<len; i++) {
			
			for(int j = i+1; j<len; j = j + 2) {
				int size = j-i+1;
				
				int leftSum = 0, rightSum = 0;
				
				for(int p = 0; p<size/2; p++) {
					leftSum = leftSum + (str.charAt(i+p) - '0');
					rightSum = rightSum + (str.charAt(i+p+size/2) - '0');
				}
				
				if(leftSum == rightSum && maxLen<size) {
					maxLen = size;
				}
			}
		}
		
		System.out.print(""+maxLen);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String str = "1538023";
		longestEvenLength(str);

	}

}
