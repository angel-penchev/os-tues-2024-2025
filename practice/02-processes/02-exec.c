#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == -1) {
    perror("fork");
  } else if (pid > 0) {
    // Parent

  } else {
    // Child

    /* if (exec(...) == -1) { */
    /*   perror("exec"); */
    /* } */

    // ./head 00-introduction.c
    /* execl("./head", "./head", "00-introduction.c", NULL); */

    char *args[] = {"ls", "-la", NULL};
    execvp("ls", args);
    perror("exec");
    return 1;
  }

  return 0;
}
