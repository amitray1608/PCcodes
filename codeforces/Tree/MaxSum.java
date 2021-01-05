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


public class MaxSum {
    static class Node {
      int prefix, suffix, maxi, total;

      void init(int n) {
        prefix = suffix = maxi = total = n;
      }

      void merge (Node a, Node b) {
        this.prefix = Math.max(a.prefix, a.total + b.prefix); 
        this.suffix = Math.max(b.suffix, b.total + a.suffix);
        this.total = b.total + a.total;
        this.maxi = Math.max(a.maxi, Math.max(b.maxi, a.suffix + b.prefix));
      }
    }

  static class SegTree { 
    int N;
    Node []tree = new Node[500000];
    SegTree(int n) {
      N = n;
//      tree = new Node[N * 4 + 1];
    }
    
    void update(int n, int s, int e, int p, int v) {
      if(s > e) return;
      if(s == e) {
        tree[n].init(v);
        return;
      }
      int mid = s + e >> 1;
      if(p <= mid) update(n + n, s, mid, p, v);
      else update(n + n + 1, mid + 1, e, p, v);
      tree[n].merge(tree[n + n], tree[n + n + 1]);
    }
    
    void update(int p, int v) {
      update(1, 0, N - 1, p, v);
    }

    int query() {
      return tree[1].maxi;
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
      int a[] = new int[n];

      for(int i = 0; i < n; i++) {
        a[i] = in.nextInt();
        st.update(i, a[i]);
      }
      out.println(st.query());
      while(q > 0) {
        q--;
        int r = in.nextInt();
        int v = in.nextInt();
        st.update(r, v);
        out.println(st.query());
      }
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
