#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
	psignal(SIGINT, "tes");
}
