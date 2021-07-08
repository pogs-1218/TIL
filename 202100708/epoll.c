#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 64

// Describe how to use the epoll_wait function
void wait_event() {
  int epfd;
  int nr_event;
  struct epoll_event* events;

  events = (struct epoll_event*)malloc(sizeof(struct epoll_event) * MAX_EVENTS);
  if (!events) {
    perror("malloc");
    return;
  }

  // Wait the MAX_EVENTS number of epoll_event infinitely(-1)
  nr_event = epoll_wait(epfd, events, MAX_EVENTS, -1);
  if (nr_event == -1) {
    perror("epoll_wait");
    return;
  }
}

int main() {
  int epfd, fd, ret;
  struct epoll_event event;

  // Create the epoll descriptor.
  epfd = epoll_create1(0);
  if (epfd == -1) {
    perror("epoll_create");
    return 1;
  }

  event.data.fd = fd;
  event.events = EPOLLIN | EPOLLOUT;

  // epoll_ctl. (control?), add, del, mod
  //  Link the file descriptor with a specific event.
  ret = epoll_ctl(epfd, EPOLL_CTL_ADD, fd, &event);
  if (ret == -1) {
    perror("epoll_ctl");
    return 1;
  }

  if (close(epfd) == -1) {
    perror("close");
    return 1;
  }
  return 0;
}