

class room {
	float length;
float breadth;
void getdata(float x, float y)
{
	length=x;
	breadth=y;
	
}

};
public class roomarea
{
public static void main (String args[])
{
	float area;
	room room1 = new room();
	room1.getdata(6,8);
	area=room1.length*room1.breadth;
	System.out.println("area="+area);
}
};