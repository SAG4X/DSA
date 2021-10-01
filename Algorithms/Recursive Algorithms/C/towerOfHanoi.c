#include<stdio.h>
int cnt=0;

void move(int,char,char,char);

int main(){
	int disk;
	printf("Input num of disks : ");
	scanf("%d",&disk);
	move(disk,'A','B','C');
	return 0;
}

void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		++cnt;
		printf("\n%5d: Move disk 1 from %c to %c", cnt, a, c);
		return;
	}
	else
	{
		move(n-1, a, c, b);
		++cnt;
		printf("\n%5d: Move disk %d from %c to %c", cnt, n, a, c);
		move(n-1, b, a, c);
		return;
	}
}
