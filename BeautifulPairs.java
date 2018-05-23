import java.util.*;

public class BeautifulPairs{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>();
        ArrayList<Integer> b = new ArrayList<Integer>();
        for(int i = 0; i < n; i++){
            a.add(sc.nextInt());
        }
        for(int i = 0; i < n; i++){
            b.add(sc.nextInt());
        }
        int counter = 0;
        for(int i = 0; i < a.size() && i >= 0; i++){
            for(int j = 0; j < b.size() && j >= 0; j++){
                if((int) a.get(i) == (int) b.get(j)){
                    a.remove(i);
                    b.remove(j);
                    i--;
                    j--;
                    counter++;
                    break;
                }
            }
        }
       // System.out.println(counter);
        if(a.size() > 0 && b.size() > 0){
            counter++;
        }
        else if(a.size() == 0 && b.size() == 0){
            if(counter > 0) counter--;
        }
        System.out.println(counter);
	}
}