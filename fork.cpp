/*
#!/bim/sh
a = 5
b = 10

val = 'expr$a + $b'
echo "$a + $b : $val"
val2 = 'expr $b - $a'
echo "$b - $a: $val2"

___________________________

p = 7;

for((m = 1; m < p; m++))
do
	for((a = i; a < p; a++))
	do
	echo -ne " ";
	done

	for((n = 1; n < m; n++))
	do
	echo -ne "#";
	done

	for((i = 1; i < m; i++))
	do
	echo -ne "#";
	done

	echo;
done

__________________________________________

#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

void forkcount() {
	int x = 1;
	if(fork() == 0) {
		cout << "child has x = " << ++x << endl;
	} else {
		cout << "Parent has x = " << --x << endl;
	}
}

int main() {
	forkcount();
	return 0;
}

*/

#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main() {
	int pid;
	pid = fork();
	if(pid == 0) {
		cout << "Child Process id: " << getpid() << '\n';
		cout << "Parent Process id; " << getppid() << '\n';
	}
	return 0;
}

