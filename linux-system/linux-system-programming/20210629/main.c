#include <poll.h>
#include <stdio.h>
#include <unistd.h>

#define TIMEOUT 5  // sec

int main() {
  struct pollfd fds[2];
  int ret = 0;

  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;

  fds[1].fd = STDOUT_FILENO;
  fds[1].events = POLLOUT;

  ret = poll(fds, 2, TIMEOUT * 1000);
  if (ret == -1) {
    perror("poll");
    return 1;
  }

  if (!ret) {
    printf("%d seconds elapsed.\n", TIMEOUT);
    return 0;
  }

  if (fds[0].revents & POLLIN) printf("stdin is readable\n");

  if (fds[1].revents & POLLOUT) printf("stdout is writable\n");

  return 0;
}