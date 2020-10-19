import java.util.*;
import java.lang.*; 
public class Solution3{
   public int solution(String s){
      int n = s.length(), count = 0;
       while (n > 0) {
         if(n == 1){
            if((int)(s.charAt(n-1) - '0') == 3){
               count+=2;
               break;
            }
            if((int)(s.charAt(n-1)- '0') == 1)
               break;
         }
            if ((int)(s.charAt(n-1) - '0')% 2 == 0) {
              String ans = ""; 
              int idx = 0; 
              char []num = s.toCharArray(); 
              int temp = num[idx] - '0', divisor = 2; 
              while (temp < divisor) 
                  temp = temp * 10 + (num[++idx] - '0'); 
              idx +=1; 
              while (num.length > idx) { 
                  ans += (temp / divisor) ; 
                  temp = (temp % divisor) * 10 + num[idx++] - '0'; 
              } 
            
              if (ans.length() == 0) 
                  s = "0"; 
              else
               s = ans; 
               n = s.length();
               count++;
            }else{
               int x;
               if(n == 1){
                  x = s.charAt(n-1)-'0';
               }else{
                  x = s.charAt(n-2)-'0';
                  x *= 10;
                  x += s.charAt(n-1)-'0';
               }
               if ((x-1)%4 == 0){
                  x = (int)s.charAt(n-1)-'0';
                  s.insert(n-1, (x-1) + '0');
                  count++;
               }else{
                  x = (int)s.charAt(n-1)-'0';
                  s.insert(n-1, (x+1) + '0');
                  count++;
               }
            }
       }
     
      return count; 
   }
   public static void main(String []args){
      System.out.println(solution("15"));
   }
};
