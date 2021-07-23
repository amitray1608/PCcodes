import java.util.HashSet;
import java.util.Iterator;

public class HashSets {

	public static void main(String[] args) {
		HashSet<String> set = new HashSet<>();
		
		set.add("Ryuzaki");
		set.add("Itadori");
		set.add("Hanzo");
		set.add("Sasuke");
		
		Iterator<String> it = set.iterator();
		while (it.hasNext())
			System.out.println(it.next());
	}

}

