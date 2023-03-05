import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Utwor {
	public void create(String autor, String wykonawca, int czas) {
		setAutor(autor);
		setCzas(czas);
		setWykonawca(wykonawca);
	}
	public void print() {
		System.out.println(autor + " " + wykonawca + " " + czas);
	}
	public void setAutor(String autor) {
		this.autor = autor;
	}

	public void setWykonawca(String wykonawca) {
		this.wykonawca = wykonawca;
	}

	public void setCzas(int czas) {
		this.czas = czas;
	}

	String autor, wykonawca;
	int czas;
}
class CD {
	CD() {
		utwory = new ArrayList<>();
	}

	public void create(String tytul, String wydawca, String wykonawca, int rok, float cena) {
		setTytul(tytul);
		setWydawca(wydawca);
		setWykonawca(wykonawca);
		setRok(rok);
		setCena(cena);
	}

	public void setTytul(String tytul) {
		this.tytul = tytul;
	}

	public void setWydawca(String wydawca) {
		this.wydawca = wydawca;
	}

	public void setWykonawca(String wykonawca) {
		this.wykonawca = wykonawca;
	}

	public void setRok(int rok) {
		this.rok = rok;
	}

	public void setCena(float cena) {
		this.cena = cena;
	}

	public void print()
	{
		System.out.println("tytul: "+tytul);
		System.out.println("wydawca: "+wydawca);
		System.out.println("wykonawca: "+wykonawca);
		System.out.println("rok: "+rok);
		System.out.println("cena: "+cena);
		System.out.println("utwory: ");
		for (Utwor u : utwory) {
			System.out.print("\t");
			u.print();
		}
	}

	public void add(Utwor u) {
		if(utwory.size() >= 10)
			return;

		utwory.add(u);
	}

	public Utwor getUtwor(int n) {
		return utwory.get(n);
	}
	String tytul, wydawca, wykonawca;
	int rok;
	float cena;
	List<Utwor> utwory;
}

class Kolekcja {
	Kolekcja() {
		plyty = new ArrayList<>();
	}
	public void add(CD cd) {
		if(plyty.size() >= 10)
			return;

		plyty.add(cd);
	}
	List<CD> plyty;
}
class Main {
	public static void main(String[] args) {
		Kolekcja kolekcja = new Kolekcja();
		Scanner input = new Scanner(System.in);
		String[] cmd;

		System.out.println("addcd tytul wydawca wykonawca rok cena");
		System.out.println("printcd cdID");
		System.out.println("editcd cdID tytul wydawca wykonawca rok cena");
		System.out.println("addsong cdID autor wykonawca czas");
		System.out.println("printsong cdID songID");
		System.out.println("editsong cdID songID autor wykonawca czas");
		System.out.println();

		do {
			cmd = input.nextLine().split(" ");
			switch (cmd[0]) {
				case "addcd": {
					CD cd = new CD();
					cd.create(cmd[1], cmd[2], cmd[3], Integer.parseInt(cmd[4]), Float.parseFloat(cmd[5]));
					kolekcja.add(cd);
					break;
				}
				case "printcd":
					kolekcja.plyty.get(Integer.parseInt(cmd[1])).print();
					break;
				case "editcd": {
					int id = Integer.parseInt(cmd[1]);
					CD cd = kolekcja.plyty.get(id);
					cd.create(cmd[2], cmd[3], cmd[4], Integer.parseInt(cmd[5]), Float.parseFloat(cmd[6]));
					kolekcja.plyty.set(id, cd);
					break;
				}
				case "addsong": {
					int cd = Integer.parseInt(cmd[1]);
					Utwor u = new Utwor();
					u.create(cmd[2], cmd[3], Integer.parseInt(cmd[4]));
					kolekcja.plyty.get(cd).add(u);
					break;
				}
				case "printsong":
					kolekcja.plyty.get(Integer.parseInt(cmd[1])).getUtwor(Integer.parseInt(cmd[2])).print();
					break;
				case "editsong": {
					int cd = Integer.parseInt(cmd[1]);
					int s = Integer.parseInt(cmd[2]);
					Utwor u = kolekcja.plyty.get(cd).getUtwor(s);
					u.create(cmd[3], cmd[4], Integer.parseInt(cmd[5]));
					kolekcja.plyty.get(cd).utwory.set(s, u);
					break;
				}
			}

		} while(!cmd[0].equals("exit"));
	}
}
