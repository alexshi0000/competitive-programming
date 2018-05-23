import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class Snake extends Thread implements KeyListener{
	
	static Bit head;
	static Bit tail;
	static ArrayList<Bit> bits = new ArrayList<Bit>();
	static JFrame frame;
	static boolean restart = false;
	static int food_x;
	static int food_y;
	static boolean special = false;
	static boolean blue = false;
	static int score = 0;
	static boolean keyReleased = false;
	
	public static class Paint extends JPanel{
		private static final long serialVersionUID = 1L;
		public void paintComponent(Graphics g){
			g.setColor(Color.black);
			g.fillRect(0,0,this.getWidth(),this.getHeight());
			g.setColor(Color.green);
			for(Bit focus : bits){
				g.fillRect((this.getWidth()/2 + focus.x)-2, (this.getHeight()/2 - focus.y)-2, 4, 4);
			}
			if(special){
				g.setColor(Color.yellow);
			}
			else if(blue){
				g.setColor(Color.blue);
			}
			else{
				g.setColor(Color.red);
			}
			g.fillRect((this.getWidth()/2 + food_x)-2, (this.getHeight()/2 - food_y)-2, 4, 4);
			g.setColor(Color.white);
			g.drawString("Score: "+score,this.getWidth() - 70, 10);
			
			//head.x > 240 || head.x < -240 || head.y > 230 || head.y < -235
		}
	}
	
	public static class Bit{
		int x = 0;
		int y = 0;
		int d = 0;												//0 is up, 1 is right, 2 is down, 3 is left
		Bit parent = null;
		Bit(int x, int y, int d){
			this.x = x;
			this.y = y;
			this.d = d;
			this.parent = tail;
			tail = this;
		}
		Bit(){}
		public void move(){										//no change in direction
			if(d == 0) y+=4;
			else if(d == 1) x+=4;
			else if(d == 2) y-=4;
			else if(d == 3) x-=4;
		}
		public static void update(int dir){						//changing directions
			if(dir == 0 && head.d == 2) return;
			if(dir == 1 && head.d == 3) return;
			if(dir == 3 && head.d == 1) return;
			if(dir == 2 && head.d == 0) return;
			if(keyReleased){
				head.d = dir;
				keyReleased = false;
			}
		}
		public static void update(){
			for(Bit b: bits){
				b.move();
			}
			for(int i = bits.size()-1; i >= 0; i--){			//updating starting from its tail
				if(bits.get(i).parent != null && bits.get(i).d != bits.get(i).parent.d) bits.get(i).d = bits.get(i).parent.d;
			}
		}
		public static void addBit(){
			if(tail.d == 0) bits.add( new Bit(tail.x,tail.y-4,tail.d));
			else if(tail.d == 1) bits.add( new Bit(tail.x-4,tail.y,tail.d));
			else if(tail.d == 2) bits.add( new Bit(tail.x,tail.y+4,tail.d));
			else if(tail.d == 3) bits.add( new Bit(tail.x+4,tail.y,tail.d));
		}
		public static boolean safe(){							//object collision detection
			for(Bit b: bits){
				if(b != head && b.parent != head && head.x == b.x && head.y == b.y){
					return false;
				}
				if(head.x > frame.getWidth()/2-5 || head.x < -1*(frame.getWidth()/2)+5 || head.y > frame.getHeight()/2-15 || head.y < -1*(frame.getHeight()/2)+15){
					return false;
				}
			}
			return true;
		}
		public static void getFood(){
			food_y = (int)(Math.random()*-430 + 215);
			food_x = (int)(Math.random()*-430 + 215);
			int chance = (int)(Math.random()*24);
			if(chance <= 6) special = true;
			else if(chance >= 20) blue = true;
			for(Bit b: bits){
				if(food_y == b.y && food_x == b.x){
					getFood();
					break;
				}
			}
		}
		public static void gotFood(){
			if(Math.abs(food_x-head.x) <= 4 && Math.abs(food_y-head.y) <= 4){
				if(special){
					int length = (int)(Math.random()*2+2);
					for(int i = 1; i <= length; i++){
						Bit.addBit();
					}
					special = false;
				}
				else if(blue){
					int length = (int)(Math.random()*10+10);
					for(int i = 1; i <= length; i++){
						Bit.addBit();
					}
					blue = false;
				}
				else{
					Bit.addBit();
				}
				score = bits.size();
				getFood();
			}
		}
	}

	public static void init(){
		frame = new JFrame();
		frame.setSize(500,500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setTitle("Snake - The Game");
		frame.setVisible(true);
		frame.addKeyListener(new Snake());
	}
	
	public static class Menu extends JPanel{
		private static final long serialVersionUID = 1L;
		public void paintComponent(Graphics g){
			g.setColor(Color.black);
			g.fillRect(0,0,this.getWidth(),this.getHeight());
			g.setColor(Color.green);
			g.drawString("PRESS R TO INSERT COIN",this.getWidth()/2-70,this.getHeight()/2-10);
		}
	}
	
	public static class GameOver extends JPanel{
		private static final long serialVersionUID = 1L;
		public void paintComponent(Graphics g){
			g.setColor(Color.black);
			g.fillRect(0,0,this.getWidth(),this.getHeight());
			g.setColor(Color.green);
			g.drawString("GAME OVER R TO RESTART",this.getWidth()/2-70,this.getHeight()/2-10);
		}
	}
	
	public static void reset(){
		bits = new ArrayList<Bit>();
		head = null;
		tail = null;
		score = 0;
	}
	
	public static void main(String[] args) {
		init();
		while(true){
			frame.add(new Menu());
			frame.setVisible(true);
			while(true){
				try{
					Thread.sleep(10);
				}catch(Exception e){	
				}
				if(restart) break;
			}
			if(restart){
				head = new Bit(0,0,3);
				tail = head;
				bits.add(head);
				Bit.addBit();
				Bit.addBit();
				Bit.getFood();
				while(true){
					if(!Bit.safe()){
						break;
					}
					else{
						frame.add(new Paint());
						frame.setVisible(true);
						try{
							Thread.sleep(25);
						}catch(Exception e){	
						}
						Bit.update();
						Bit.gotFood();
					}
				}
				restart = false;
			}
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			frame.add(new GameOver());
			frame.setVisible(true);
			while(true){
				try{
					Thread.sleep(1);
				}catch(Exception e){	
				}
				if(restart) break;
			}
			reset();
		}
	}

	public void keyPressed(KeyEvent e) {
		keyReleased = true;
		if(e.getKeyCode() == KeyEvent.VK_R){
			restart = true;
		}
		else if(e.getKeyCode() == KeyEvent.VK_W){
			if(head != null) Bit.update(0);
			return;
		}
		else if(e.getKeyCode() == KeyEvent.VK_D){
			if(head != null) Bit.update(1);
			return;
		}
		else if(e.getKeyCode() == KeyEvent.VK_S){
			if(head != null) Bit.update(2);
			return;
		}
		else if(e.getKeyCode() == KeyEvent.VK_A){
			if(head != null) Bit.update(3);
			return;
		}
	}

	public void keyReleased(KeyEvent e) {
	}
	public void keyTyped(KeyEvent e) {
		
	}
}
