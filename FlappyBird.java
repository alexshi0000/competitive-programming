import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.*;
import javax.swing.*;
import java.util.*;

public class FlappyBird implements KeyListener{
	
	static JFrame frame;					
	static int x = 100, y = 100;				
	static boolean collided = false;			
	static double velocity = 0;					
	static double level = 0;
	static int score = 0;
	static double wave = -1; 
	static int target = 0;
	static int counter = 0;
	
	public static class Block{
		static ArrayList<Block> blocks = new ArrayList<Block>();
		int x,y;
		Block(){}
		public static void generate(int n){
			Block newBlock = new Block();
			newBlock.y = (int)(Math.random()*0.4*frame.getHeight()+0.2*frame.getHeight());
			newBlock.x = frame.getWidth()+25*n;
			blocks.add(newBlock);
		}
	}
	
	public static void update(){
		if(y <= 0 || y >= frame.getHeight()) collided = true;
		for(int i = 0 ;i < Block.blocks.size(); i++){
			Block b = Block.blocks.get(i);
			if(b.x < -50){
				Block.generate(1);
				Block.blocks.remove(i); 
				return; 
			}
			if(counter % 2 == 0) b.y += wave;
			if(counter == 75){
				counter = 0;
				if((int)(Math.random()*2)==0) wave = -wave;
			}
			b.x = (int) (b.x - 2);
			if(x > b.x-22 && x < b.x+50 && ( y+20 >= b.y+120 || y <= b.y )){
				collided = true;
				return;
			}
		}
		y += velocity;
		velocity += 0.18;
	}
	
	public static void init(){
		frame = new JFrame();
		frame.setSize(600,500);
		frame.setVisible(true);
		frame.add(new canvas());
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.addKeyListener(new FlappyBird());
	}
	
	public static class canvas extends JPanel{
		private static final long serialVersionUID = 1L;
		public void paintComponent(Graphics g){
			g.setColor(new Color(110,140,255));
			g.fillRect(0,0,frame.getWidth(), frame.getHeight());
			g.setColor(new Color(5,165,30));
			for(Block b: Block.blocks){
				g.fillRect(b.x,0,50,frame.getHeight());
				g.setColor(new Color(110,140,255));
				g.fillRect(b.x,b.y,50,120);
				g.setColor(new Color(5,165,30));
			}
			g.setColor(Color.white);
			g.fillRect(x, y, 20, 20);
			g.setColor(Color.white);
			g.drawString("SCORE: "+score, 20, 20);
		}
	}

	public static void main(String[] args) {
		init();
		while(true){
			Block.blocks = new ArrayList<Block>();
			Block.generate(1);
			Block.generate(10);
			Block.generate(19);
			while(!collided){
				update();
				frame.add(new canvas());
				frame.setVisible(true);
				try{
					Thread.sleep(12);
				}catch(Exception e){
					
				}
				score++;
				counter++;
			}
			try{
				Thread.sleep(10);
			}catch(Exception e){
				
			}
		}
	}

	public void keyPressed(KeyEvent arg0) {
		if(arg0.getKeyCode() == KeyEvent.VK_SPACE){
			velocity = -5.2;
		}
		if(arg0.getKeyCode() == KeyEvent.VK_R){
			if(collided){
				collided = false;
				x = 100;
				y = frame.getWidth()/2;
				velocity = 0;
				level = 0;										//this is pretty cool
				score = 0;
			}
		}
	}

	public void keyReleased(KeyEvent arg0) {
		
	}

	public void keyTyped(KeyEvent arg0) {
	
	}

}
