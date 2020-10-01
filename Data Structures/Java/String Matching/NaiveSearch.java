import java.util.ArrayList;

public class NaiveSearch{
	
	public static ArrayList<Integer> naiveSearch(String text, String pattern){
		ArrayList<Integer> positions = new ArrayList<Integer>();
		
		int n = text.length();
		int m = pattern.length();
		
		for(int i = 0;i<=n-m;i++){
			int j;
			for(j = 0;j<m;j++){
				if(text.charAt(i+j) != pattern.charAt(j)){
					break;
				}
			}
			if(j == m){
				positions.add(i);
			}
		}
		
		return positions;
	}
	
	public static void main(String[] args){
		String text = "ABCCBACABACABACABACACAACBABAC";
		String pattern = "BAC";
		ArrayList<Integer> positions = naiveSearch(text,pattern);
		System.out.println("Text: "+text);
		System.out.println("Pattern: "+pattern);
		System.out.println();
		
		for(int position: positions){
			System.out.println("Pattern found at position: " + position);
		}
	}
}
