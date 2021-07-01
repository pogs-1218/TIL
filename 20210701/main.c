#include <fcntl.h>  // open
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  // stream을 열고 데이터를 읽기
  FILE* in_file = NULL;
  int in_fd = 0;
  char* buf = NULL;
  size_t buf_size = 0;

  in_file = fopen("sample", "r");
  if (in_file == NULL) {
    perror("fopen");
    return 1;
  }
  in_fd = fileno(in_file);

  // read buffer를 생성하기 위해 파일사이즈를 가져온다.
  // 문제: lseek처럼 파일 오프셋을 변경하나?
  // fseek(in_file, 0, SEEK_END);
  buf_size = lseek(in_fd, 0, SEEK_END);
  // 다시 시작위치로 돌려놓는다.
  lseek(in_fd, 0, SEEK_SET);

  buf = (char*)malloc(buf_size);

  if (fread(buf, buf_size, 1, in_file) < 1) {
    perror("fread");
    return 1;
  }

  // 파일디스크립터를 통해 stream을 열고 데이터를 쓰기.
  FILE* out_file = NULL;
  int out_fd = 0;

  out_fd = open("result", O_CREAT | O_WRONLY | O_TRUNC, 0644);
  if (out_fd == -1) {
    perror("open");
    return 1;
  }
  out_file = fdopen(out_fd, "w");
  if (out_file == NULL) {
    perror("fopen");
    return 1;
  }

  if (fwrite(buf, buf_size, 1, out_file) < 1) {
    perror("fwrite");
    return 1;
  }

  // 핸들 정리.
  fclose(in_file);
  fclose(out_file);  // stream을 닫으면 fd도 닫힘!

  return 0;
}