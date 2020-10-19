//Ryuzaki
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

class REPLESXa{
  //Solution starts here:
  
  public static void main(String[] args) throws IOException {
    OutputStream outputStream = System.out;
    Reader in = new Reader();
    PrintWriter out = new PrintWriter(outputStream);
    int T = 1;
    T = in.nextInt();
    for(int TT = 1 ; TT <= T ; TT++){
      int n = in.nextInt();
      int x = in.nextInt();
      int p = in.nextInt();
      int k = in.nextInt();
      int []a = new int[n];
      for(int i = 0; i < n; ++i) {
        a[i] = in.nextInt();
      }
      /*
      int i = 1; iith = 1;
      while(i < n && iith < p) {
        if(a[i] != a[i - 1]) {
          iith++;
        }
        i++;
      }
      */
      Arrays.sort(a);
      int count = 0, P = p;
      boolean flag = false;
      while(P-- > 0) {
        int i = 1, iith = 1;
        while(i < n && iith < p) {
          if(a[i] != a[i - 1]) {
            iith++;
          }
          i++;
        }
        if(a[--i] == x && iith == p) {
          flag = true;
          break;
        } else {
          i = 1; iith = 1;
          while(i < n && iith < k) {
            if(a[i] != a[i - 1]) {
              iith++;
            }
            i++;
          }
          a[--i] = x;
        }
        Arrays.sort(a);
        count++;
      }
      if(flag == true)
        out.println(count);
      else
        out.println(-1);
    }
    out.close();
  }

  //Soultion ends here:
  
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
/*
8 4 6 3
2 3 3 7 9 10 11 13
ans = 4
*/
