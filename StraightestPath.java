    import java.util.*;
    public class StraightestPath{
    	public static void print(boolean[][] arr){
    		for(int i = 0; i < arr.length; i++){
    			for(int j = 0; j < arr[0].length; j++)
    				System.out.print(arr[i][j]+" ");
    			System.out.println();
    		}
    	}
    	public static void print(int[][] arr){
    		for(int i = 0; i < arr.length; i++){
    			for(int j = 0; j < arr[0].length; j++){
    				if(arr[i][j] == Integer.MAX_VALUE)
    					System.out.print("-1"+" ");
    				else
    					System.out.print(arr[i][j]+" ");
    			}
    			System.out.println();
    		}
    	}
    	public static void print(char[][] arr){
    		for(int i = 0; i < arr.length; i++){
    			for(int j = 0; j < arr[0].length; j++)
    				System.out.print(arr[i][j]+" ");
    			System.out.println();
    		}
    	}
    	//=================== SOLUTION ==========================================
    	//1 for up, 2 for right , 3 for down, and 4 for left. 0 for undetermined direction
    	static int min = Integer.MAX_VALUE;
    	static int[][][] minTurns;
    	static char[][] graph;
    	public static boolean safe(int currRo, int currCo){
    		return !(currRo < 0 || currRo >= graph.length || currCo < 0 || currCo >= graph[0].length || graph[currRo][currCo] == '*');
    	}
        public static int getMin(int ro, int co){
            return Math.min(Math.min(Math.min(Math.min(minTurns[0][ro][co],minTurns[1][ro][co]),minTurns[2][ro][co]),minTurns[3][ro][co]),minTurns[4][ro][co]);
        }
    	public static void search(int ro, int co, int direction){
    		if(graph[ro][co] == 'H' && getMin(ro,co) < min)
                min = getMin(ro,co);
            else{
                int currMin = minTurns[direction][ro][co];
                if(currMin == Integer.MAX_VALUE)
                    return;
                if(direction == 0){
                    if(safe(ro+1,co) && currMin < minTurns[3][ro+1][co]){
                        minTurns[3][ro+1][co] = currMin;
                        search(ro+1,co,3);
                    }
                    if(safe(ro-1,co) && currMin < minTurns[1][ro-1][co]){
                        minTurns[1][ro-1][co] = currMin;
                        search(ro-1,co,1);
                    }
                    if(safe(ro,co+1) && currMin < minTurns[2][ro][co+1]){
                        minTurns[2][ro][co+1] = currMin;
                        search(ro,co+1,2);
                    }
                    if(safe(ro,co-1) && currMin < minTurns[4][ro][co-1]){
                        minTurns[4][ro][co-1] = currMin;
                        search(ro,co-1,4);
                    }
                }
                 if(direction == 1){
                    if(safe(ro+1,co) && currMin+1 < minTurns[3][ro+1][co]){
                        minTurns[3][ro+1][co] = currMin+1;
                        search(ro+1,co,3);
                    }
                    if(safe(ro-1,co) && currMin < minTurns[1][ro-1][co]){
                        minTurns[1][ro-1][co] = currMin;
                        search(ro-1,co,1);
                    }
                    if(safe(ro,co+1) && currMin+1 < minTurns[2][ro][co+1]){
                        minTurns[2][ro][co+1] = currMin+1;
                        search(ro,co+1,2);
                    }
                    if(safe(ro,co-1) && currMin+1 < minTurns[4][ro][co-1]){
                        minTurns[4][ro][co-1] = currMin+1;
                        search(ro,co-1,4);
                    }
                }
                 if(direction == 2){
                    if(safe(ro+1,co) && currMin+1 < minTurns[3][ro+1][co]){
                        minTurns[3][ro+1][co] = currMin+1;
                        search(ro+1,co,3);
                    }
                    if(safe(ro-1,co) && currMin+1 < minTurns[1][ro-1][co]){
                        minTurns[1][ro-1][co] = currMin+1;
                        search(ro-1,co,1);
                    }
                    if(safe(ro,co+1) && currMin < minTurns[2][ro][co+1]){
                        minTurns[2][ro][co+1] = currMin;
                        search(ro,co+1,2);
                    }
                    if(safe(ro,co-1) && currMin+1 < minTurns[4][ro][co-1]){
                        minTurns[4][ro][co-1] = currMin+1;
                        search(ro,co-1,4);
                    }
                }
                 if(direction == 3){
                    if(safe(ro+1,co) && currMin < minTurns[3][ro+1][co]){
                        minTurns[3][ro+1][co] = currMin;
                        search(ro+1,co,3);
                    }
                    if(safe(ro-1,co) && currMin+1 < minTurns[1][ro-1][co]){
                        minTurns[1][ro-1][co] = currMin+1;
                        search(ro-1,co,1);
                    }
                    if(safe(ro,co+1) && currMin+1 < minTurns[2][ro][co+1]){
                        minTurns[2][ro][co+1] = currMin+1;
                        search(ro,co+1,2);
                    }
                    if(safe(ro,co-1) && currMin+1 < minTurns[4][ro][co-1]){
                        minTurns[4][ro][co-1] = currMin+1;
                        search(ro,co-1,4);
                    }
                }
                 if(direction == 4){
                    if(safe(ro+1,co) && currMin+1 < minTurns[3][ro+1][co]){
                        minTurns[3][ro+1][co] = currMin+1;
                        search(ro+1,co,3);
                    }
                    if(safe(ro-1,co) && currMin+1 < minTurns[1][ro-1][co]){
                        minTurns[1][ro-1][co] = currMin+1;
                        search(ro-1,co,1);
                    }
                    if(safe(ro,co+1) && currMin+1 < minTurns[2][ro][co+1]){
                        minTurns[2][ro][co+1] = currMin+1;
                        search(ro,co+1,2);
                    }
                    if(safe(ro,co-1) && currMin < minTurns[4][ro][co-1]){
                        minTurns[4][ro][co-1] = currMin;
                        search(ro,co-1,4);
                    }
                }
            }
    	}
    	public static void main(String[] args){
    	    //System.out.println("WTF");
    		Scanner sc = new Scanner(System.in);
    		int ro = sc.nextInt();
    		int co = sc.nextInt();
    		int startRo = -1;
    		int startCo = -1;	//invalid
    		graph = new char[ro][co];
    		minTurns = new int[5][ro][co];
    		for(int i = 0; i < ro; i++){
    		    String s = sc.next();
    			for(int j = 0; j < co; j++){
    				graph[i][j] = s.charAt(j);
    				if(graph[i][j] == 'V'){
    					startRo = i;
    					startCo = j;
                    }
                    for(int k = 0; k < 5; k++)
                        minTurns[k][i][j] = Integer.MAX_VALUE;
                }
            }
            minTurns[0][startRo][startCo] = 0;
            minTurns[1][startRo][startCo] = 0;
            minTurns[2][startRo][startCo] = 0;
            minTurns[3][startRo][startCo] = 0;
            minTurns[4][startRo][startCo] = 0;
    		search(startRo, startCo, 0);
    		System.out.println(min);
    	}
    }
