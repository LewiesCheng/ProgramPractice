package statictest;


public class StaticTest {

	public static void main(String[] args) {
		Student[] stu = new Student[3];
		stu[0] = new Student("20142344068", "Liuch", 'ÄĞ');
		stu[1] = new Student("20142344100", "Hony", 'ÄĞ');
		stu[2] = new Student("20142344109", "Lucy", 'Å®');
		
		for (Student e : stu) {
			e.setNumber();
			System.out.println(e.getNumber() + ": " + e.getId() + "  " + e.getName() + "  " + e.getSex());
		}
		
		int n = Student.getNextNumber();
		System.out.println("Next number is " + n);
	}

}

class Student {
	private static int nextNumber = 1;
	private int number;
	private String id;
	private String name;
	private char sex;
	
	public Student (String i, String n, char s) {
		id = i;
		name = n;
		sex = s;
		number = 0;
	}
	public String getId () {
		return id;
	}
	public String getName () {
		return name;
	}
	public char getSex () {
		return sex;
	}
	public int getNumber () {
		return number;
	}
	public void setNumber () {
		number = nextNumber;
		nextNumber ++;
	}
	public static int getNextNumber() {
		return nextNumber;
	}
}