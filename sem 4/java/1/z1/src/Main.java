import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("Ile ocen: ");
		int s = input.nextInt();
		double avg = 0;

		for(int n = 0; n < s; n++) {
			System.out.print("Przedmiot "+(n+1)+": ");
			avg += input.nextInt();
		}

		avg /= s;
		System.out.println("Średnia: " + avg + " Stypendium: " + (avg > 4.1 ? "TAK" : "NIE"));
	}
}
