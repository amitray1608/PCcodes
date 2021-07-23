import java.util.*;

   class Main   {

       public static void main(String args[])       {

           List<Integer> obj = new ArrayList<Integer>(5);

           for (int i = 0; i < 5; ++i)     

          obj.add(i);  

          obj.remove((Integer)2);

         System.out.print(obj);       

}   

}
