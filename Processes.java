import java.util.*;
import java.io.*;

public class Processes {

	/*   <----- to Toronto             <----- to Toronto
	 *    =============\    shared   /==============
	 *                  >===========<
	 *    =============/             \==============
	 * to Montreal ----->              to Montreal ----->
	 *
	 *   torontoX      startX        endX       montrealX  x ---> +
	 */

	//lets assume that the two trains are of the same model and will have to travel at the same speed
	public static int torontoX, startX, endX, montrealX, speed,
				animationSpeed;

	public static class BinarySemaphore {

		int counter; //in a binary semaphore the counter can only be two values 1 and 0
		BinarySemaphore() {
			//because this is a binary semaphore, there is no need to add a fair FIFO or unfair option along with the limit for the counter to reach
			counter = 0;
		}

		public synchronized void aquire() {
			counter = 1;
		}

		public synchronized void release() {
			counter = 0;
		}

		public synchronized boolean tryAquire() {
			if (counter == 1)
				return false;
			else
				return true;
		}
	}

	public static BinarySemaphore trackLock = new BinarySemaphore();

	public static class Train extends Thread {

		private String trainName;
		private int x;        //displacement
		private int v; //unlike speed, velocity has a direction, either positive or negative in this situation

		public Train(String name, int x, int v) {
			trainName = name;
			this.x    = x;
			this.v    = v;
		}

		private Train() {
			//force users to use the full constructor
		}

		public void move() {
			if (x < startX || x > endX) {
				//simulate v meters traveled in 1 second
				if (x == torontoX || x == montrealX)
					System.out.println(this);
				x += v;
				try {
					this.sleep(animationSpeed);
					//velocity is in meters per seconds
				} catch (Exception e) {
					//do something
				}
				if (x >= torontoX && x <= montrealX)
					System.out.println(this);
			} else if (x >= torontoX && x <= montrealX) {
				while (!trackLock.tryAquire()) {
					try {
						this.sleep(animationSpeed);
					} catch (Exception e) {
						//do something
					}
					System.out.println(trainName + " holding at " + x + ".");
				}
				trackLock.aquire();
				boolean outOfSharedTrack = false; //once train is out of the shared track
				while (!outOfSharedTrack) {
					x += v;
					try {
						this.sleep(animationSpeed);
					} catch(Exception e) {
						//do something
					}
					System.out.println(this);
					outOfSharedTrack = x < startX || x > endX;
				}
				trackLock.release();
			}
			//otherwise we would not need to do anything, thread is simply holding until it is terminated by os or user app
		}

		public void run() {
			while (true)
				move();
		}

		public int getX() {
			return x;
		}

		public int getV() {
			return v;
		}

		public String getTrainName() {
			return trainName;
		}

		public String toString() {
			//print the status of this train
			String ret;
			if (x == torontoX)
				ret = trainName + " holding at Toronto.";
			else if (x == montrealX)
				ret = trainName + " holding at Montreal.";
			else if (x == startX)
				ret = trainName + " at " + x + " reached start of shared track.";
			else if (x == endX)
				ret = trainName + " at " + x + " reached end of shared track.";
			else if (x > startX && x < endX)
				ret = trainName + " at " + x + " on shared track.";
			else
				ret = trainName + " at " + x + ".";
			return ret;
		}
	}

	public static void main(String[] args) {
		torontoX       = 0;
		startX         = 10;
		endX           = 40;
		montrealX      = 60;
		speed          = 1;
		animationSpeed = 500;
		Train a = new Train("Toronto to Montreal express", torontoX,
		 	 speed);
		Train b = new Train("Montreal to Toronto express", montrealX,
			-speed);
		a.start();
		b.start();
	}
}