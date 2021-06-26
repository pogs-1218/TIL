#include <errno.h>
#include <fcntl.h>  // open, creat, openat
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>  // read, write

int sync_read_file(const char *path, char *buf, ssize_t len, ssize_t *out_len);
int sync_write_file(const char *path, const char *buf, ssize_t len, bool sync);

int main() {
  int read_fd = -1, write_fd = -1;
  ssize_t file_len = 0;
  char buf[256];

  read_fd = sync_read_file("testfile", buf, sizeof(buf), &file_len);
  write_fd = sync_write_file("outfile", buf, file_len, false);

  close(read_fd);
  close(write_fd);

  return 0;
}

int sync_read_file(const char *path, char *buf, ssize_t buf_len,
                   ssize_t *out_len) {
  int fd = open(path, O_RDONLY);
  if (fd == -1) {
    perror("open error\n");
    return -1;
  }

  off_t file_size = lseek(fd, 0, SEEK_END);
  if (buf_len < file_size) {
    // error?
    return -1;
  }
  *out_len = file_size;

  if (lseek(fd, 0, SEEK_SET) == -1) {
    perror("lsseek error\n");
    return -1;
  }

  int ret = 0, len = file_size;
  while (len != 0 && (ret = read(fd, buf, len))) {
    if (ret == -1) {
      if (errno == EINTR) continue;
      perror("read error\n");
      return -1;
    }
    buf += ret;
    len -= ret;
  }

  return fd;
}

int sync_write_file(const char *path, const char *buf, ssize_t len, bool sync) {
  int fd = creat(path, 0644);
  if (fd == -1) {
    perror("creat error\n");
    return -1;
  }

  int ret = -1;
  while (len != 0 && (ret == write(fd, buf, len))) {
    if (ret == -1) {
      if (errno == EINTR) continue;
      perror("write error\n");
      return -1;
    }
    buf += ret;
    len -= ret;
  }
  if (sync) {
    if (fdatasync((fd)) == -1) {
      perror("fdatasync error\n");
    }
  }
}