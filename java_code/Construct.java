import java.util.*;

class Student 
{ 
	String name, uid;
	double cgpa; 
	

	Student(String w, String h, double d) 
	{ 
		name = w; 
		uid = h; 
		cgpa = d; 
	} 


	Student() 
	{ 
		name = "Amit Kumar";
		uid = "18BCS2059";
		cgpa = 7.29;
	} 


	
	Student(double x) 
	{ 
		name = "James Kumar";
		uid = "18BCS5092";
		cgpa = x;
		
	} 

	void display() 
	{ 
		System.out.println("Name = " + name + "\n" + "UID = " + uid + "\ncgpa = " + cgpa);
	} 
} 

public class Construct
{ 
	public static void main(String args[]) 
	{ 

		Student obj1 = new Student("sumit", "18BCS9502", 9.99); 
		Student obj2 = new Student(8.5); 
		Student obj3 = new Student(); 

		System.out.println("\nObject 1 called Constructor with arguments: \n"); 
		 obj1.display(); 

		 System.out.println("\nObject 2 called Constructor with one argument: \n"); 
			obj2.display(); 
			
		System.out.println("\nObject 3 called Constructor without argument:\n");
		obj3.display();  
		 
	} 
} 
