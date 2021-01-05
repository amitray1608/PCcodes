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


public class MAX {

  static class SegTree {
    int N;
    int []tree;

    public SegTree(int n) {
      N = n;
      tree = new int[n * 4 + 1];
      for(int i = 0; i < 4 * n + 1; i++) 
        tree[i] = 0;
    }

    void update(int n, int s, int e, int l, int r, int v) {
      if(s > e || s > r || e < l) return;
      if(l <= s && e <= r) {
        tree[n] = Math.max(tree[n], v);
        return;
      }
      int mid = s + e >> 1;
      update(n + n, s, mid, l, r, v);
      update(n + n + 1, mid + 1, e, l, r, v);
    }
    
    void push(int n) {
      tree[n + n] = Math.max(tree[n + n], tree[n]);
      tree[n + n + 1] = Math.max(tree[n + n + 1], tree[n]);
      tree[n] = 0; 
    }

    int query(int n, int s, int e, int l, int r) {
      if(s > e || s > r || e < l) return 0;
      if(l <= s && e <= r) return tree[n];
      push(n);
      int mid = s + e >> 1;
      if(l <= mid)
        return query(n + n, s, mid, l, r);
      else
        return query(n + n + 1, mid + 1, e, l, r);
    }
 
    void update(int l, int r, int v) {
      update(1, 0, N - 1, l, r, v);
    }
   
    long query(int l, int r) {
      return query(1, 0, N - 1, l, r);
    }

  }


  public static void main(String[] args) throws IOException {
    OutputStream outputStream = System.out;
    Reader in = new Reader();
    PrintWriter out = new PrintWriter(outputStream);
    int T = 1;
    //T = in.nextInt();
    for(int TT = 1 ; TT <= T ; TT++){
      int n = in.nextInt();
      int q = in.nextInt();
      SegTree st = new SegTree(n);
      while(q > 0) {
        q--;
        int tp, l, r, v;
        tp = in.nextInt();
        if(tp == 1) {
          l = in.nextInt();
          r = in.nextInt();
          v = in.nextInt();
          st.update(l, r - 1, v);
        } else {
          l = in.nextInt();
          out.println(st.query(l, l));
        }
      }    }
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
