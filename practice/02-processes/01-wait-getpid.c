#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  /* pid_t pid = fork(); */
  /* if (pid == -1) { */
  /*   perror("fork"); */
  /*   return 1; */
  /* } */

  int pid = fork();

  if (pid > 0) {
    int ret = waitpid(1, NULL, 0);
    printf("waitpid return value: %d\n", ret);

    if (ret == -1) {
      perror("waitpid");
    }
  }

  return 0;
}
