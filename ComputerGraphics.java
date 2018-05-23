import java.util.*;
public class ComputerGraphics{
	public static int angleOfReflection(int surface, int angle){
		if(surface == 0){
			if(angle == 270)
				return 90;
			if(angle > 270 && angle < 360)
				return 360 - angle;
			if(angle > 180 && angle < 270)
				return 180 - (angle - 180);
			return -1;
		}
		else if(surface == 1){
			if(angle == 0 || angle == 360)
				return 180;
			if(angle > 0 && angle < 90)
				return 180 - angle;
			if(angle > 270 && angle < 360)
				return 180 + (360 - angle);
			return -1;
		}
		else if(surface == 2){
			if(angle == 90)
				return 270;
			if(angle < 180 && angle > 90)
				return (180 - angle) + 180;
			if(angle < 90 && angle > 0)
				return 360 - angle;
			return -1;
		}
		else if(surface == 3){
			if(angle == 180)
				return 0;
			if(angle > 180 && angle < 270)
				return 360 - (angle - 180);
			if(angle > 90 && angle < 180)
				return 180 - angle;
			return -1;
		}
		return -1;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("please specify the surface: ");
		int n = sc.nextInt();
		System.out.print("please give the angle of incidence in degrees: ");
		int angle = sc.nextInt();
		System.out.print("angle of reflection in standard mode: ");
		System.out.println(angleOfReflection(n,angle));
	}
}