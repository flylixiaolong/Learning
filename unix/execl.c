#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status;
	if((pid=fork())==0){
		printf("child\n");
		execl("/bin/do", "sh", "-c", "os -l", (char *)0);
		printf("dododo\n");
		_exit(127);
	}else{
		if(waitpid(pid, &status, 0) != pid) {
			printf("sys error\n");
		}
		printf("%d\n", status);
		printf("%d\n", WEXITSTATUS(status));
		printf("%d\n", WTERMSIG(status));
		printf("parent\n");
	}
	return 0;
}
