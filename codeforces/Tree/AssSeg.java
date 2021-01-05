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


public class AssSeg {

  static class SegTree{
    int N;
    long [][]tree;

    public SegTree(int n) {
      N = n;
      tree = new long[n * 4 + 1][2];
    }

    void update(int n, int s, int e, int l, int r, int v, int curr) {
      if(s > e || s > r || e < l) return;
      if(l <= s && e <= r) {
        tree[n][0] = v;
        tree[n][1] = curr;
        return;
      }
      int mid = s + e >> 1;
      update(n + n, s, mid, l, r, v, curr);
      update(n + n + 1, mid + 1, e, l, r, v, curr);
    }

    void push(int n) {
      if(tree[n][1] > tree[n + n][1]) {
        tree[n + n][0] = tree[n][0];
        tree[n + n][1] = tree[n][1];
      }
      if(tree[n][1] > tree[n + n + 1][1]) {
        tree[n + n + 1][0] = tree[n][0];
        tree[n + n + 1][1] = tree[n][1];
      }
      tree[n][0] = 0;
      tree[n][1] = 0;
    }

    long query(int n, int s, int e, int l, int r) {
      if(s > e || s > r || e < l) return 0;
      if(l <= s && e <= r) return tree[n][0];
      push(n);
      int mid = s + e >> 1;
      if(l <= mid) 
        return query(n + n, s, mid, l, r);
      else
        return query(n + n + 1, mid + 1, e, l, r);
    }

    void update(int l, int r, int v, int curr) {
      update(1, 0, N - 1, l, r, v, curr);
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
      int count = 0;
      while(q > 0) {
        q--;
        int tp, l, r, v;
        tp = in.nextInt();
        if(tp == 1) {
          count++;
          l = in.nextInt();
          r = in.nextInt();
          v = in.nextInt();
          st.update(l, r - 1, v, count);
        } else {
          l = in.nextInt();
          out.println(st.query(l, l));
        }
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
