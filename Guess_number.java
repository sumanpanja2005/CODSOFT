import java.util.Random;
import java.util.Scanner;

public class Guess_number {
	public static void main(String[] args) {
		int x=0,y=8;
		System.out.println("Your Number of attempt is 8...");
		Random rand = new Random();
		int number = rand.nextInt(100);
		Scanner sc = new Scanner(System.in);
		boolean correct=false;
		int count=0;
		do {
			System.out.print("ENTER YOUR NUMBER :");
			int you=sc.nextInt();
			if(you>number) {
				System.out.println("ITS to bigger .....");
				x++;
				y--;
				System.out.println("Remaining Attempt :"+y);
				count++;
			}
			else if(you<number) {
				System.out.println("ITS to smaller .....");
				x++;
				y--;
				System.out.println("Remaining Attempt :"+y);
				count++;
			}
			else {
				correct=true;
			}
		} while(!correct && x<9 && y>0);
		if(correct) {
			System.out.println("YOU GOT IT.....YOU WON ");
			count++;
			System.out.println("YOUR NUMBER OF Attempt  IS :"+count);
		}
	}
}
