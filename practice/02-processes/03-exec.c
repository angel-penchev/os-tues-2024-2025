#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    return 1;
  }

  if (pid == -1) {
    perror("fork");
  } else if (pid > 0) {
    // Parent
    int wstatus;
    /* wait(&wstatus); */
    waitpid(-1, &wstatus, 0);
    printf("wstatus: %b\n", wstatus);
    printf("WIFEXITED: %d\n", WIFEXITED(wstatus));
    printf("WEXITSTATUS: %d\n", WEXITSTATUS(wstatus));
    if (WIFEXITED(wstatus) != 1 || WEXITSTATUS(wstatus) != 0) {
      // handle child error
      write(STDERR_FILENO, "child error\n", strlen("child error\n"));
    }
    printf("Parent completed\n");

  } else {
    // Child

    /* char **ls_argv; */
    /* memcpy(ls_argv, argv, sizeof(argv)); */
    /* ls_argv[0] = "ls"; */
    /* printf("ls_argv[0]: %s\n", ls_argv[0]); */
    /* printf("argv[0]: %s\n", ls_argv[0]); */

    execvp("sleep", argv);
    perror("exec");
    return 1;
  }

  return 0;
}
