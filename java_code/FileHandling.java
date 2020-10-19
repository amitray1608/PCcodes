import java.io.*;

public class FileHandling{
		public static void main(String args[]) throws Exception{
			System.out.println("Amit Kumar\n18BCS2059");
			FileWriter fw = new FileWriter("input.txt");
			String s = "Example of file handling.";
			fw.write(s);
			fw.close();
			
			FileReader fr = new FileReader("input.txt");
			BufferedReader br = new BufferedReader(fr);
			
			int i;
			while((i = br.read()) != -1){
				System.out.print((char) i);
			}
			br.close();
			fr.close();
		}
	
}
