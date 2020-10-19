import java.util.*;
import java.lang.Math;
import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {
    public static int solution(int[][] area) {
        // Your code here
        int n = area.length;
        int m = area[0].length;
        int ans = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
			int flag = 0;
				if(area[i][j] == 1){
					flag = 1;
					area[i][j] = 0;
				}
		int x = 0, y = 0;
		Queue<Triple> q = new ArrayDeque<>();
		boolean[][] vis = new boolean[n][m];
		vis[x][y] = true;
		q.add(new Triple(x, y, 0, 1));
		int dx[] = { -1, 0, 0, 1 };
		int dy[] = { 0, -1, 1, 0 };
		int mini = Integer.MAX_VALUE;
		while (!q.isEmpty()){
			Triple T = q.poll();
			x = T.x;
			y = T.y;
			int count = T.count;
			int used = T.used;
			if (x == n-1 && y == m-1){
				mini = count;
				break;
			}
			for (int it = 0; it < 4; it++){
				int xx = x+dx[it], yy = y + dy[it];
				if ((xx >= 0) && (xx < n) && (yy >= 0) && (yy < m) && area[xx][yy]  == 0 && !vis[xx][yy]){
					vis[xx][yy] = true;
					//if(area[xx][yy] == 1 && used == 1)
						//q.add(new Triple(xx, yy, count + 1, 0));
					//else if(area[xx][yy] == 0)
						q.add(new Triple(xx, yy, count + 1, used));
				}
			}
		}
		ans = Math.min(mini, ans);
		if(flag == 1)
			area[i][j] = 1;
		}
		}
    	return ans+1; 
    }
     public static void main(String []argv){
         Scanner sc= new Scanner(System.in);
         int n = sc.nextInt();
         int m = sc.nextInt();
         int [][] area = new int[n][m];
         for(int i =  0; i < n;  i++)
 			for(int j = 0; j < m; j++)
 				area[i][j] = sc.nextInt();

 		System.out.print(solution(area)); 
 	}
};
class Triple{
	int x, y, count, used;
	Triple(int x, int y, int count, int used) {
		this.x = x;
		this.y = y;
		this.count = count;
		this.used = used;
	}
};
/*
7 7
0 1 1 0 0 0 0 
0 1 1 0 1 1 0
0 1 1 0 1 1 0
0 1 1 1 1 1 0
0 1 1 0 1 1 0
0 1 1 0 1 1 0
0 0 0 0 1 1 0
*/
