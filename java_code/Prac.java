//import java.util.Scanner;

class Vehicle{
		int rate;
		String brand;
		
		void set_brand(String b)
		{
			brand = b;
		}
		void set_rate(int r)
		{
			rate = r;
		}
		String get_brand()
		{
			return brand;
		}
		int get_rate()
		{
			return rate;
		}
	
}

class Car extends Vehicle{
	
	void details()
	{
		System.out.println("Car Brand : " + get_brand());
		System.out.println("Car rate  : " + get_rate());
	}
	
	void class_of_car()
	{
		System.out.println("This class car is a subclass of class Vehicle");
	}
	
}

class Prac
{
	public static void main(String []args)
	{
			Car obj = new Car();
			obj.set_brand("Lamborghini");
			obj.set_rate(10000000);
			obj.class_of_car();
			obj.details();
	}	
}
