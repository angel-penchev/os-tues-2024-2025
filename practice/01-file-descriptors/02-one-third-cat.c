#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#define BYTES_TO_READ 1

int main(int argc, char **argv) {
  // Check if correct amount of args is supplied
  if (argc != 2) {
    fprintf(stderr, "Invalid arguments.");
    return 1;
  }

  // Open the file specified in argv
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }

  char read_buf[BYTES_TO_READ];
  int bytes_read;
  do {
    // Read from file.
    bytes_read = read(fd, read_buf, BYTES_TO_READ);
    if (bytes_read == -1) {
      perror("read");
      close(fd);
      return -1;
    }

    // Write to the standard output
    if (write(STDIN_FILENO, read_buf, bytes_read) == -1) {
      perror("write");
    }

    // Skip 2 bytes from the current position.
    int offset = lseek(fd, 2, SEEK_CUR);

    // Print the current offset from the begining of the file after skipping 2
    // bytes.
    /* printf("<[%d]>\n", offset); */
  } while (bytes_read == BYTES_TO_READ);

  // Print the length of the file
  int offset = lseek(fd, 0, SEEK_END);
  printf("<[%d]>\n", offset);

  // Close file
  if (close(fd) == -1) {
    perror("open");
    return 1;
  }
  return 0;
}
