#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  struct rusage ru;
  int status;
  pid_t pid;

  if (!fork()) {
    return 1;
  }

  pid = wait(&status);
  if (pid == -1) {
    perror("wait");
  }
  printf("pid = %d\n", pid);

  if (WIFEXITED(status)) {
    printf("Normal termination with exit status = %d\n", WEXITSTATUS(status));
  }
  if (WIFSIGNALED(status)) {
    printf("Kille dby signal=%d%s\n", WTERMSIG(status),
           __WCOREDUMP(status) ? " (dumpled core" : "");
  }
  if (WIFSTOPPED(status)) {
    printf("Stopped by signal=%d\n", WSTOPSIG(status));
  }

  return 0;
}