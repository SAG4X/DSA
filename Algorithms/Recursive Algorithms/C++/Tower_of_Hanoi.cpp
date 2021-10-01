#include <bits/stdc++.h> 

using namespace std; 

int cnt=0;
void move(int,char,char,char);

void move(int n, char a, char b, char c)
{
	if (n == 1)
	{
		++cnt;
		cout << "\n" << cnt << ": Move disk 1 from " << a << " to " << c;
		return;
	}
	else
	{
		move(n-1, a, c, b);
		++cnt;
		cout << "\n" << cnt << ": Move disk " << n << " from " << a << " to " << c;
		move(n-1, b, a, c);
		return;
	}
}

int main(){
	int disk;
	cout << "Input num of disks : ";
	cin >> disk;
	move(disk,'A','B','C');
	return 0;
}
