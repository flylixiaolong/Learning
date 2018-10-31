#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
	printf("%d,%d", getuid(),getgid());	
	struct passwd *pass;
	pass = getpwuid(getuid());
	printf("%s", pass->pw_shell);

}

