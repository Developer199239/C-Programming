
public class Main {

	
	static int countRotations(int arr[],int n) {
		int min_index = 0,min_value = arr[0];
		for(int i = 1; i<n; i++) {
			if(arr[i] < min_value) {
				min_index = i;
				min_value = arr[i];
			}
		}
		
		return min_index;
	}
	
	public static void main(String[] args) {
		int arr[] = {7,9,1,2,3,4,5};
		int n = arr.length;
		System.out.println(countRotations(arr, n));
	}

}
