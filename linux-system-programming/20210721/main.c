#include <stdint.h>  // uintmax_t , %ju
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  struct stat sb;
  int ret;

  if (argc < 2) {
    fprintf(stderr, "usage: %s <file>\n", argv[0]);
    return 1;
  }
  ret = stat(argv[1], &sb);
  if (ret) {
    perror("stat");
    return 1;
  }
  printf("%s is %ld bytes\n", argv[1], sb.st_size);

  printf("file type: ");
  switch (sb.st_mode & __S_IFMT) {
    case __S_IFBLK:
      printf("block device node\n");
      break;
    case __S_IFCHR:
      printf("character device node\n");
      break;
    case __S_IFDIR:
      printf("directory\n");
      break;
    case __S_IFIFO:
      printf("FIFO\n");
      break;
    case __S_IFLNK:
      printf("symbolic link");
      break;
    case __S_IFREG:
      printf("regular file\n");
      break;
    case __S_IFSOCK:
      printf("socket\n");
    default:
      printf("unkonwn\n");
      break;
  }

  printf("inode number: %ju\n", sb.st_ino);
  printf("ownership: UID=%ju, GID=%ju\n", (uintmax_t)sb.st_uid,
         (uintmax_t)sb.st_gid);
  printf("Preferred I/O block size: %jd\n", (intmax_t)sb.st_blksize);
  printf("File size: %jd bytes\n", (intmax_t)sb.st_size);
  printf("Blocks allocated: %jd\n", (intmax_t)sb.st_blocks);

  return 0;
}