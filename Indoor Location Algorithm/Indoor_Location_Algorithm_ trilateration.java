
public class Indoor_Location_Algorithm {
	
	Indoor_Location_Algorithm(){
		
	}

	void getMeetingPoints(int distanceA, int distanceB, int distanceC, int pointA1, int pointA2, int pointB1,
			int pointB2, int pointC1, int pointC2) {
		int w = (distanceA * distanceA) - (distanceB * distanceB)  - (pointA1 * pointA1) - (pointA2 * pointA2) + (pointB1 * pointB1) + (pointB2 * pointB2);
		
		int z = (distanceB * distanceB) - (distanceC * distanceC) - (pointB1 * pointB1) - (pointB2 * pointB2) + (pointC1 * pointC1) + (pointC2 * pointC2);
		
		
		
		int a = (w * (pointC2 - pointB2) - z * (pointB2 - pointA2));
		int b = (2 * ((pointB1 - pointA1) * (pointC2 - pointB2) - (pointC1 - pointB1) * (pointB2 - pointA2)));
		
		
		 int x = a / b;
		 
		 int y =  (w - 2 * x * (pointB1 - pointA1)) / (2 * (pointB2 - pointA2));
		 
		 int y2 = (z - 2 * x * (pointC1 - pointB1)) / (2 * (pointC2 - pointB2));
		 
		 y = (y + y2) / 2;
		 
		 System.out.println("X = "+x+", Y = "+y);
		
		
	}

	public static void main(String[] args) {
		Indoor_Location_Algorithm algo = new Indoor_Location_Algorithm();
		
		int dis1 = 1,dis2 = 2, dis3 = 2;
		int pointA1 = 0,pointA2 = 0;
		int pointB1 = 2, pointB2 = 3;
		int pointC1 = 2, pointC2 = 1;
		
		algo.getMeetingPoints(dis1, dis2, dis3, pointA1, pointA2, pointB1, pointB2, pointC1, pointC2);
	}

}
