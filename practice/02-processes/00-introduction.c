#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  pid_t pid = fork();
  if (pid == -1) {
    if (errno == ENOMEM) {
      // handle if no memory
    }

    perror("fork");
    return 1;
  }

  if (pid == 0) {
    printf("START: Child process\n");
    sleep(5); // simulate 5 seconds of work
    printf("END: Child process\n");
    return 0;
  }

  if (pid > 0) {
    printf("START: Parent process\n");

    /* int ret = waitpid(pid, NULL, WNOHANG); */
    int ret = waitpid(pid, NULL, 0);

    printf("waitpid return value: %d\n", ret);

    printf("END: Parent process\n");

    /* printf("%d\n", pid); */
    return 0;
  }

  return 0;
}
