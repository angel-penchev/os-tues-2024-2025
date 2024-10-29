#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BYTES_TO_READ 10

int main(int argc, char **argv) {
  // Check if correct amount of args is supplied.
  if (argc != 2) {
    fprintf(stderr, "Invalid arguments.");
    return 1;
  }

  // Open the file specified in argv.
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char read_buf[BYTES_TO_READ];

  // Read from file.
  read(fd, read_buf, BYTES_TO_READ);
  // Write to the standard output
  if (write(STDIN_FILENO, read_buf, BYTES_TO_READ) == -1) {
    perror("write");
  }

  // Close file
  if (close(fd) == -1) {
    perror("open");
    return 1;
  }

  return 0;
}
