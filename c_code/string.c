#include<stdio.h>
#include<string.h>
int main()
{

	char a[20], b;
	printf("Enter your first name: \n");
	scanf("%[^\n]]s", a);
	printf("Enter the character to be find : \n");
	scanf("%c", &b);
	//gets(a);
	int i ;
	for( i = 0; i < 20; i++)
	{
		if(a[i] == b)
		{
				printf("character found:\n");
				break;
		}
	}
		if(i == 20)
			printf("Charecter not found");
		return 0;
}
