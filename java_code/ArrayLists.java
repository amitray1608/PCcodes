import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

class Employee {
	private int id;
	private String name;
	private String address;
	private Double salary;
	
	public Employee(int id, String name, String address, Double salary) {
		super();
		this.id = id;
		this.name = name;
		this.address = address;
		this.salary = salary;
	}	
	
	public int getId() {
		return id;
	}

	public String toString() {
		return "Employee [id=" + id + ", name=" + name + ", address=" + address + ", salary=" + salary + "]\n";
	}
}

public class ArrayLists {

	public static void main(String[] args) {
		List<Employee> list = new ArrayList<>();
		
		list.add(new Employee(1001, "Skuna", "Mohali Punjab, India", 10000.0));
		list.add(new Employee(1002, "Dabi", "Karnatak, India", 20000.0));
		list.add(new Employee(1003, "Tobirama", "Meghalaya, India", 35000.0));
		list.add(new Employee(1004, "Ryuzaki", "Bihar, India", 400000.0));
		
		Iterator<Employee> it = list.iterator();
		int searchId = 1003;
		while (it.hasNext()) {
			Employee emp = it.next();
			if (emp.getId() == searchId)
				System.out.println(emp);
		}
	}

}
