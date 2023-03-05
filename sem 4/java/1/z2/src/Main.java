import java.util.Scanner;

class Zad2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);

		System.out.print("N: ");
		int n = input.nextInt();
		System.out.println(func1(n));
		System.out.println(func2(n));
	}

	public static long func1(int n) {
		long r = 1;
		for(int x = 2; x <= n; x++)
			r *= x;

		return r;
	}

	public static double func2(int n) {
		double r = 0;
		for(int x = 1; x <= n; x++)
			r += (x % 2 == 1 ? 1.0 : -1.0)/(x+n);

		return r;
	}
}
