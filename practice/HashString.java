import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

public class HashString {

	public static void main(String[] args) {
		Map<String, String> map = new HashMap<>();
		
		map.put("18BCS2059", "Amit");
		map.put("18BCS2587", "Jatin");
		map.put("18BCS3330", "Harshit");
		
		Set<Entry<String, String>> st = map.entrySet();
		Iterator<Entry<String, String>> it = st.iterator();
		
		while (it.hasNext()) {
			Map.Entry<String, String> me = it.next();
			
			if (me.getKey().equals("18BCS2587")) {
				System.out.println("Key 18BCS2587 exists");
				break;
			}
		}
		
		st = map.entrySet();
		it = st.iterator();
		
		while (it.hasNext()) {
			Map.Entry<String, String> me = it.next();
			
			if (me.getValue().equals("Amit")) {
				System.out.println("Value Amit exists");
				break;
			}
		}
		
		st = map.entrySet();
		it = st.iterator();
		
		while (it.hasNext()) {
			Map.Entry<String, String> me = it.next();
			System.out.println(me);
		}
	}

}
