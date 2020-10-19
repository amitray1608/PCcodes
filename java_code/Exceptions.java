package exceptions;
class Exceptions extends Exception{
  private int v;
  public Exceptions()
  {
  }
  public Exceptions(int n)
  {
      v=n;
  }
  public String getMessage()
  {
      return " The Value "+v+" exceeds 9 ";
  }
   public void smallSum(int a,int b) throws Exceptions
   {
       if(a>9)
       {
           throw new Exceptions(a);
       }
       else
       {
System.out.println("Sum = "+(a+b));
       }
   }
    public static void main(String[] args) {
		System.out.println("Amit Kumar");
		System.out.println("18BCS2059");
        Exceptions e=new Exceptions();
        try
        {
e.smallSum(10,8);
        }
catch(Exceptions v)
         {
System.out.println(v.getMessage());
         }
    }
}
