import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class FindingSubseq {
	static HashMap<Character,Integer> indexMap;
	static HashMap<Integer,Character> charMap;
	public static void print(int[][] arr){
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[0].length; j++)
				System.out.print(arr[i][j]+" ");
			System.out.println();
		}
	}
	public static void initIndexMap(){									//creating maps
		indexMap = new HashMap<Character,Integer>();
		charMap = new HashMap<Integer,Character>();
    	indexMap.put('a',0);	charMap.put(0,'a');
    	indexMap.put('b',1);	charMap.put(1,'b');
    	indexMap.put('c',2);	charMap.put(2,'c');
    	indexMap.put('d',3);	charMap.put(3,'d');
    	indexMap.put('e',4);	charMap.put(4,'e');
    	indexMap.put('f',5);	charMap.put(5,'f');
    	indexMap.put('g',6);	charMap.put(6,'g');
    	indexMap.put('h',7);	charMap.put(7,'h');
    	indexMap.put('i',8);	charMap.put(8,'i');
    	indexMap.put('j',9);	charMap.put(9,'j');
    	indexMap.put('k',10);	charMap.put(10,'k');
    	indexMap.put('l',11);	charMap.put(11,'l');
		indexMap.put('m',12);	charMap.put(12,'m');
		indexMap.put('n',13);	charMap.put(13,'n');
		indexMap.put('o',14);	charMap.put(14,'o');
		indexMap.put('p',15);	charMap.put(15,'p');
		indexMap.put('q',16);	charMap.put(16,'q');
		indexMap.put('r',17);	charMap.put(17,'r');
		indexMap.put('s',18);	charMap.put(18,'s');
		indexMap.put('t',19);	charMap.put(19,'t');
		indexMap.put('u',20);	charMap.put(20,'u');
		indexMap.put('v',21);	charMap.put(21,'v');
		indexMap.put('w',22);	charMap.put(22,'w');
		indexMap.put('x',23);	charMap.put(23,'x');
		indexMap.put('y',24);	charMap.put(24,'y');
		indexMap.put('z',25);	charMap.put(25,'z');
	}
	public static String solution(String word, int k){
		if(word == "" || word.equals(""))
			return "";
		int[][] memo = new int[26][word.length()];
		int[] lastPos = new int[26];
		for(int i = memo[0].length-1; i >= 0; i--){
			for(int j = memo.length-1; j >= 0; j--){
				if(i < memo[0].length-1)
					memo[j][i] = memo[j][i+1];
				char c = word.charAt(i);
				if((int)indexMap.get(c) == j){		//matching character
					memo[j][i]++;
					if(lastPos[j] == 0)
						lastPos[j] = i;
				}
			}
		}
		print(memo);
		System.out.println(Arrays.toString(lastPos));
		for(int i = memo.length-1; i >= 0; i--){
			for(int j = 0; j < memo[0].length; j++){
				if(memo[i][j] >= k){
					char letter = charMap.get(i);
					String ans = "";
					for(int m = 0; m < memo[i][j]; m++)
						ans += letter;
					int start = lastPos[i] + 1;
					return ans + solution(word.substring(start),k);
				}
			}
		}
		return "";
	}
	public static void main(String[] args) {
		initIndexMap();
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int k = sc.nextInt();
		System.out.println(solution(s,k));
	}
}
