import java. util. *;
public class Solution {
    public static int solution(int[] l) {
        // Your code here
		int n = l.length;
		int sum = 0, ss = 0;
		Arrays.sort(l);
		for(int i = 0; i < n; i++){
			sum = sum + l[i];
		}
		ss = sum;
		if(n == 1){
			if(sum % 3 == 0)
				return l[0];
			else
				return 0;
		}
		if(n == 2){
			if(sum % 3 == 0)
				return (l[1]*10+l[0]);
			else{
				if(l[1]%3 == 0)
					return l[1];
				else if(l[0]%3 == 0)
					return l[0];
				else
					return 0;
			}
		}
		boolean flag = false;
		if(sum % 3 == 1){
			int i = 0;
			for(i = 0; i < n; i++){
				if(l[i] % 3 == 1){
					l[i] = -1;
					flag = true;
					break;
				}
			}
			if(i == n){
				int count = 0;
				for(i = 0; i < n; i++){
					if(l[i]% 3 == 2){
						l[i] = -1;
						count++;
					}
					if(count == 2){
						flag = true;
						break;
					}
				}
			}
		}else if(sum % 3 == 2){
			int i = 0;
			for(i = 0; i < n; i++){
				if(l[i] % 3 == 2){
					l[i] = -1;
					flag = true;
					break;
				}
			}
			if(i == n){
				int count = 0;
				for( i = 0; i < n; i++){
					if(l[i]% 3 == 1){
						l[i] = -1;
						count++;
					}
					if(count == 2){
						flag = true;
						break;
					}
				}
			}
		}
		int s = 0;
		sum = 0;
		//System.out.println("ok");
		for(int i = n-1; i >= 0; i--){
			if(l[i] == -1)
				continue;
			s = s*10 + l[i];
		    sum += l[i];
		}
		//System.out.println(sum);
		if(sum%3 != 0 || (ss %3 != 0 && !flag))
		    return 0;
			
		return s;
    }
    public static void main(String [] args){
		int []l = {1, 4, 3, 1};
		int s = solution(l);
		System.out.println(s);
	}
}
