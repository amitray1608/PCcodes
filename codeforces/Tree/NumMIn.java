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


public class NumMIn {

  static class SegTree {
    int N, inf;
    int [][]tree;

    SegTree(int n, int a[]) {
      N = n;
      inf = Integer.MAX_VALUE;
      tree = new int[n * 4 + 1][2];
      for(int i = 0; i < n * 4 + 1; i++) tree[i][0] = Integer.MAX_VALUE;
      build(1, 0, n - 1, a);
    }

    void merge(int n) {
      if(tree[n + n][0] == tree[n + n + 1][0]){ 
        tree[n][0] = tree[n + n][0];
        tree[n][1] = tree[n + n][1] + tree[n + n + 1][1];
      } 
      else if(tree[n + n][0] < tree[n + n + 1][0]) {
        tree[n][0] = tree[n + n][0];
        tree[n][1] = tree[n + n][1];
      } 
      else {
        tree[n][0] = tree[n + n + 1][0];
        tree[n][1] = tree[n + n + 1][1];
      }
    }

    void build(int n, int s, int e, int a[]) {
      if( s > e ) return;
      if(s == e) {
        tree[n][0] = a[s];
        tree[n][1] = 1;
        return;
      }
      int mid = (s + e) / 2;
      build(n + n, s, mid, a);
      build(n + n + 1, mid + 1, e, a);
      merge(n);
    }

    void update(int n, int s, int e, int p, int v) {
      if(s > e) return;
      if(s == e) {
        tree[n][0] = v;
        tree[n][1] = 1;
        return;
      }
      int mid = (s + e) / 2;
      if(p <= mid) update(n + n, s, mid, p, v);
      else update(n + n + 1, mid + 1, e, p, v);
      merge(n);
    }

    int[] query(int n, int s, int e, int l, int r) {
      int []x = {inf, 0};
      if(s > e || s > r || e < l) return x;
      if(l <= s && e <= r) return tree[n];
      int mid = (s + e) / 2;
      int a[] = query(n + n, s, mid, l, r);
      int b[] = query(n + n + 1, mid + 1, e, l, r);
      if(a[0] == b[0]) {
        a[1] += b[1];
        return a;
      } else if(a[0] < b[0]) return a;
      else return b;
    }

    void update(int p, int v) {
      update(1, 0, N - 1, p, v);
    }
 
    int[] query(int l, int r) {
      return query(1, 0, N - 1, l, r);
    }

  };

  public static void main(String[] args) throws IOException {
    OutputStream outputStream = System.out;
    Reader in = new Reader();
    PrintWriter out = new PrintWriter(outputStream);
    int T = 1;
    //T = in.nextInt();
    for(int TT = 1 ; TT <= T ; TT++){
      int n, q;
      n = in.nextInt();
      q = in.nextInt();
      int []a = new int[n];
      for(int i = 0; i < n; i++) a[i] = in.nextInt();
      SegTree st = new SegTree(n, a);
      
      while(q > 0) {
        q--;
        int tp, l, r;
        tp = in.nextInt();
        l = in.nextInt();
        r = in.nextInt();
        if(tp == 1) {
          st.update(l, r);
        } else {
          int ans[] = st.query(l, r - 1);
          out.println(ans[0] + " " + ans[1]);
        }
      }
//      out.println(st.inf);
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
