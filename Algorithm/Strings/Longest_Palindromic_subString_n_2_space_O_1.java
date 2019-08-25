
//https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/

public class Longest_Palindromic_subString_n_2_space_O_1 {

	
	static void printSubStr(String str,int low,int hight) {
		String subString = str.substring(low,hight+1);
		System.out.println("Palindrome subString : "+subString);
	}
	
	static void longestPalSubString(String str) {
		int maxLenght = 1;
		
		int start = 0;
		int len = str.length();
		
		int low,high;
		
		for(int i =1; i<len; i++) {
			// find the longest even length palindrome 
			// center points as i-1 and i.
			low = i -1; 
			high = i;
			
			while(low >= 0 && high < len
					&& str.charAt(low) == str.charAt(high)
					) {
				if(high - low + 1 > maxLenght) {
					start = low;
					maxLenght = high - low + 1;
				}
				
				low--;
				high++;
			}
			
			// find the longest odd length palindrome with center point as i
			low = i-1; 
			high = i+1;
			
			while(low >= 0 && high < len
					&& str.charAt(low) == str.charAt(high)
					) {
				if(high-low+1 > maxLenght) {
					start = low;
					maxLenght = high - low + 1;
				}
				low--;
				high--;
			}
			
		}
		
		System.out.println("Longest palindrome substring lenght : "+maxLenght);
		printSubStr(str, start,start+maxLenght-1);
		
		
	}
	
	
	public static void main(String[] args) {
		String str = "abab";
		longestPalSubString(str);
	}

}
