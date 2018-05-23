import java.util.*;
import java.io.*;

public class BridgeCrossing{

    public static class Person{
        int speed;
        String name;
        boolean end = false;
        Person(String name, int speed){
            this.name = name;
            this.speed = speed;
        }
    }

    public static void main(String[] args){
        try{
            BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
            int m = Integer.parseInt(sc.readLine());
            int n = Integer.parseInt(sc.readLine());
            Person[] arr = new Person[n];
            int[] memo = new int[n];
            int[] group = new int[n];                           
            for(int i = 0; i < n; i++){
                String id = sc.readLine();
                int speed = Integer.parseInt(sc.readLine());
                arr[i] = new Person(id,speed);
            }
            for(int i = 0; i < n; i++){
                if(i < m){
                    memo[i] = max(0,i,arr);                    //has to be in group
                    group[i] = -1;
                }
                else{
                    int min = Integer.MAX_VALUE;
                    int index = -1;
                    for(int j = m; j >= 1; j--){
                        if(max(i-j+1,i,arr) + memo[i-j] < min){
                            min = max(i-j+1,i,arr) + memo[i-j];
                            index = i-j+1;
                        }
                    }
                    memo[i] = min;
                    group[i] = index;
                }
            }
            int index = n-1;
            while(true){
                if(group[index] >= 0){
                    arr[group[index]].end = true;
                    index = group[index];
                }
                else break;
                index = index-1;
                if(index == 0) break;
                
            }
           
            System.out.println("Total Time: "+memo[n-1]);
            for(int i = 0; i < n; i++){
                if(arr[i].end) System.out.println();
                System.out.print(arr[i].name+" ");
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public static int max(int lo, int hi, Person[] arr){
        int max = 0;
        for(int i = lo; i <= hi; i++){
            Person p = arr[i];
            if(p.speed > max) max = p.speed;
        }
        return max;
    }
}