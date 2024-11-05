#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILE_NAME "example-inputs/example1.txt"

int main(void) {

  // Open example1.txt for WRITE and CREATE
  int fd = open(FILE_NAME, O_RDWR | O_CREAT); // fd will be 3
  if (fd == -1) {
    return 1;
  }

  // STDIN_FILENO = 0
  // STDOUT_FILENO = 1
  // STDERR_FILENO = 2
  // fd = 3

  // Attempt read from example1.txt
  char read_buf[6]; // reads "gosho\n"
  if (read(fd, read_buf, 6) == -1) {
    perror("read");
    return 1;
  }

  // Write what is read to stdout
  // write(1, read_buf, 6);
  write(STDOUT_FILENO, read_buf, 6);

  if (read(fd, read_buf, 6) == -1) {
    perror("read");
    return 1;
  }

  write(STDOUT_FILENO, read_buf, 6);

  /* int *p1 = malloc(8); */

  char write_buf[6];
  int write_return = write(fd, write_buf, strlen(write_buf));
  if (write_return == -1) {
    // Remember to ALWAYS clear used heap memory/opened resources, if you're
    // going to exit the program.
    perror("write");
    /* free(p1); */
    close(fd);
    return 1;
  }

  /* free(p1); */

  // We can close the
  /* if (close(0) == -1) { */
  /*   perror("close"); */
  /* } */
  /* if (close(1) == -1) { */
  /*   perror("close"); */
  /* } */
  /* if (close(2) == -1) { */
  /*   perror("close"); */
  /* } */
  return 0;
}
