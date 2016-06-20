#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <list>
const char *g_command = 0;

void usage() {
	printf("usage:\n");
	printf("  protect [-s command] filename [arguments]\n");
}

int main(int argc, char *argv[]) {
	std::list<int> myList;
	myList.push_back(1);
	printf("%s",argv[0]);
	if (argc < 2) {
		usage();
		return -1;
	}
	int argi = 1;
	bool command = false;
	if (*argv[1] == '-') {
		argi = 2;
		for (const char *p = argv[1] + 1; *p; ++p) {
			if (*p == 's') {
				command = true;
				break;
			}
		}
	}
	if (command) {
		if (argi < argc) {
			g_command = argv[argi++];
		} else {
			usage();
			return -1;
		}
	}
	if (argi >= argc) {
		usage();
		return -1;
	}

	int len = strlen(argv[0]);
	char *s = new char[len + 5];
	strcpy(s, argv[0]);
	strcpy(s + len, ".pid");
	FILE *fp = fopen(s, "w");
	if (fp) {
		fprintf(fp, "%u", ::getpid());
		fclose(fp);
	}
	delete []s;

	for (;;) {

		pid_t pid = fork();
		if (pid < 0) {
			printf("fork() error:%d\n", errno);
			break;
		}

		if (pid > 0) {
			// parent process.
			int status;
			while (wait(&status) == pid) ;
			if (WIFEXITED(status)) {				//子进程正常退出
				if (WEXITSTATUS(status) == 255) {	//返回子进程退出的值
					break;
				}
			}

			if (g_command) {
				system(g_command);
			}

		} else {
			// child process.
			char *envp[] = { 0 };
			execve(argv[argi], argv + argi, envp);
			printf("execve() error:%d\n", errno);
			break;
		}

	}
	return -1;
}
