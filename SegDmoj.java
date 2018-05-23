import java.util.*;
import java.io.*;

public class SegDmoj{
	
	static int[] arr;
	static Node root;
	
	public static class Node{
		int gcd;								//greatest common divisor
		int min;								
		int max;
		int l,r;
		int value = Integer.MIN_VALUE;			//we know this is invalid value
		long sum;
		Node left, right;
		Node(int l, int r){
			this.l = l;
			this.r = r;
		}
	}
	
	public static int Gcd(int a, int b){		//a bigger than b, returns gcd
		if(a == b) return a;
		if(a == 0) return b;
		if(b == 0) return a;
		return Gcd(b,a%b);
	}
	
	public static void construct(Node focus){
		if(root == null) root = focus;
		if(focus.l == focus.r){
			focus.min = arr[focus.l];
			focus.gcd = arr[focus.l];
			focus.value = arr[focus.l];
			focus.sum = arr[focus.l];
			focus.max = arr[focus.l];
		}
		else{
			int range = focus.r - focus.l;
			focus.right = new Node(focus.l,focus.l + range/2);
			focus.left = new Node(focus.l + range/2 + 1, focus.r);
			construct(focus.right);
			construct(focus.left);
			focus.gcd = Gcd(focus.right.gcd,focus.left.gcd);
			focus.min = Math.min(focus.right.min,focus.left.min);
			focus.sum = focus.right.sum + focus.left.sum;
			focus.max = Math.max(focus.right.max,focus.left.max);
		}
	}
	
	public static int getGcd(Node focus, int l, int r)
	{
		if(l <= focus.l && r >= focus.r) return focus.gcd;
		else if(l > focus.r || r < focus.l){
			return -1;
		}
		else{
			int gcdL = getGcd(focus.left,l,r);
			int gcdR = getGcd(focus.right,l,r);
			if(gcdR == -1) return gcdL;
			if(gcdL == -1) return gcdR;
			return Gcd(gcdL,gcdR);
		}
	}
	
	public static int getMin(Node focus, int l, int r){												
		if(l <= focus.l && r >= focus.r) return focus.min;
		else if(l > focus.r || r < focus.l){ 
			return Integer.MAX_VALUE;
		}
		else return Math.min(getMin(focus.right,l,r),getMin(focus.left,l,r));
	}
	
	public static int common(Node focus, int gicd, int l, int r){
		if(focus.l >= l && focus.r <= r){ 
			return count(focus,gicd);
		}
		else if(l > focus.r || r < focus.l){
			return 0;
		}
		else{
			return common(focus.left,gicd,l,r) + common(focus.right,gicd,l,r);
		}
	}
	
	public static int count(Node focus, int gcid){
		if(focus == null) return 0;
		else if(focus.l == focus.r){
			if(focus.value == gcid) return 1;
			else 					return 0;
		}
		else{
			int counter = 0;
			if(focus.left.sum >= gcid && focus.left.max >= gcid && focus.left.min <= gcid){
				counter += count(focus.left,gcid);
			}
			if(focus.right.sum >= gcid && focus.right.max >= gcid && focus.right.min <= gcid){
				counter += count(focus.right,gcid);
			}
			return counter;
		}
	}
	
	public static void update(Node focus, int index, int value){
		if(focus.l == focus.r && focus.l == index){
			arr[index] = value;
			focus.value = value;
			focus.sum = value;
			focus.min = value;
			focus.gcd = value;
		}
		else{
			if(index >= focus.left.l && index <= focus.left.r){
				update(focus.left,index,value);
			}
			else if(index >= focus.right.l && index <= focus.right.r){
				update(focus.right,index,value);
			}	
			focus.gcd = Gcd(focus.right.gcd,focus.left.gcd);
			focus.sum = focus.right.sum + focus.left.sum;
			focus.min = Math.min(focus.right.min,focus.left.min);
			focus.max = Math.max(focus.right.max,focus.left.max);
		}
	}
	
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			String[] in = sc.readLine().split(" ");
			int n = Integer.parseInt(in[0]);
			int m = Integer.parseInt(in[1]);
			arr = new int[n];
			in = sc.readLine().split(" ");
			for(int i = 0; i < in.length; i++){
				arr[i] = Integer.parseInt(in[i]);
			}
			construct(new Node(0,arr.length-1));
			for(int i = 0; i < m; i++){
				in = sc.readLine().split(" ");
				String type = in[0];
				int l = Integer.parseInt(in[1])-1;
				int r = Integer.parseInt(in[2])-1;
				if(type.equals("Q")){
					System.out.println( common(root,getGcd(root,l,r),l,r));
				}
				else if(type.equals("M")){
					System.out.println( getMin(root,l,r));
				}
				else if(type.equals("G")){
					System.out.println( getGcd(root,l,r));
				}
				else{
					update(root,l,r+1);
				}
			}
			//print(root);
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static void print(Node root){
		if(root == null) return;
		print(root.left);
		System.out.println(root.l+" "+root.r+" "+root.value+" "+root.min+" "+root.gcd+" "+root.sum);
		print(root.right);
	}
}