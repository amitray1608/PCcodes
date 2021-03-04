import java.util.*;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;


public class TeamName {

  public static void main(String[] args) throws IOException {
    OutputStream outputStream = System.out;
    //Reader in = new Reader();
    Scanner sc = new Scanner(System.in);
    PrintWriter out = new PrintWriter(outputStream);
    int T = 1;
    T = sc.nextInt();
    for(int TT = 1 ; TT <= T ; TT++){
      int n = sc.nextInt();
      int count = 0;
      int f[] = new int[26];
      //HashMap<String, ArrayList<Character>> suf = new HashMap<String, ArrayList<Character>>();
      HashMap<Character, Set<String>> cnt= new HashMap<Character, Set<String>>();
      String s[] = new String[n];
      for (int i = 0; i < n; i++) {
        s[i] = sc.next();
        f[s[i].charAt(0) - 'a']++;
      }
      for (int i = 0; i < 26; i++) {
        Set<String> st = new HashSet<String>();
        Character x = (char)('a' + i);
        for (int j = 0; j < n; j++) {
          char y = (char)s[j].charAt(0);
          if (y == x) {
            String k = s[j].substring(1);
            st.add(k);
          }
        }
        cnt.put(x, st);
      }
      for (int i = 0; i < 26; i++) {
        Character x = (char)('a' + i);
        Set<String> st = cnt.get(x);
        for (int j = 0; j < 26; j++) {
          if (i == j) continue;
          int fr = 0, se = 0;
          Character y = (char)('a' + j);
          Set<String> stt = cnt.get(y);
          for (String it : st) {
            if (stt.size() != 0 && stt.contains(it) == false) fr++;
          }
          for (String it : stt) {
            if (st.size() != 0 && st.contains(it) == false) se++;
          }
          count += (fr * se);
        }
      }
      out.println(count);
    }
    out.close();
  }

  // InputReader from : https://www.geeksforgeeks.org/fast-io-in-java-in-competitive-programming/
  static class Reader{
    final private int BUFFER_SIZE = 1 << 16;
    private DataInputStream din;
    private byte[] buffer;
    private int bufferPointer, bytesRead;
    public Reader() {
      din = new DataInputStream(System.in);
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }
    public Reader(String file_name) throws IOException {
      din = new DataInputStream(new FileInputStream(file_name));
      buffer = new byte[BUFFER_SIZE];
      bufferPointer = bytesRead = 0;
    }
    public String readLine() throws IOException {
      byte[] buf = new byte[64]; // line length
      int cnt = 0, c;
      while ((c = read()) != -1)
      {
          if (c == '\n')
              break;
          buf[cnt++] = (byte) c;
      }
      return new String(buf, 0, cnt);
    }
    public int nextInt() throws IOException {
      int ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do{
        ret = ret * 10 + c - '0';
      }  while ((c = read()) >= '0' && c <= '9');
      if (neg)
          return -ret;
      return ret;
    }
    public long nextLong() throws IOException{
      long ret = 0;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      }
      while ((c = read()) >= '0' && c <= '9');
      if (neg)
        return -ret;
      return ret;
    }
    public double nextDouble() throws IOException{
      double ret = 0, div = 1;
      byte c = read();
      while (c <= ' ')
        c = read();
      boolean neg = (c == '-');
      if (neg)
        c = read();
      do {
        ret = ret * 10 + c - '0';
      }
      while ((c = read()) >= '0' && c <= '9');
      if (c == '.'){
        while ((c = read()) >= '0' && c <= '9'){
          ret += (c - '0') / (div *= 10);
        }
      }
      if (neg)
        return -ret;
      return ret;
    }
    private void fillBuffer() throws IOException{
      bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
      if (bytesRead == -1)
        buffer[0] = -1;
    }
    private byte read() throws IOException{
      if (bufferPointer == bytesRead)
        fillBuffer();
      return buffer[bufferPointer++];
    }
    public void close() throws IOException{
      if (din == null)
        return;
      din.close();
    }
  }
}
