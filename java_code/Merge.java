import java.util.*;

public class Merge{

void merg(int a[], int l, int mid, int h){

	int n1 = mid-l+1;
	int n2 = h-mid;
	int L[] = new int[n1];
	int  R[] = new int[n2];
		
	for(int i=0; i<n1; i++)
	L[i] = a[l+i]; 
	for(int i=0; i<n2; i++)
	R[i] = a[mid+1+i];

	int i = 0, j = 0;
	
	int k = l;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while(j<n1){
		a[k] = L[j];
		j++;
		k++;
	}

	while(i<n2){
		a[k] = R[i];
		i++;
		k++;
	}
	
}


void mergeS(int a[], int l, int h )
{
	int mid =(l + (h-l)) / 2;
	if(l<h){

	mergeS(a, l, mid);
	mergeS(a, mid+1, h);

	merg(a, l, mid, h);
}

}



public static void main(String [] args){
	Scanner in = new Scanner(System.in);
	int n = in.nextInt();
	int a[] = new int[n+1];
	for(int i = 0; i<n; i++)
	a[i] = in.nextInt();
	Merge obj = new Merge();
	obj.mergeS(a, 0, n-1);
	
	for(int i = 0; i<n; i++)
	System.out.print(a[i] + " ");

	System.out.println();
}
}
