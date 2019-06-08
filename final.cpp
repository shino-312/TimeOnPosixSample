#include <iostream>
#include <cstdio> // for perror
#include <ctime>

int main(void) {

  struct timespec ts;
  struct tm t;
  int ret;

  ret = clock_gettime(CLOCK_REALTIME, &ts);
  if (ret < 0) {
    perror("clock_gettime fail");
  }

  localtime_r(&ts.tv_sec, &t);

  char buf[32];
  ret = strftime(buf, 32, "%Y/%m/%d %H:%M:%S", &t);
  if (ret == 0) {
    perror("strftime fail");
  }

  char output[32];
  const int msec = ts.tv_nsec / 1000000;
  ret = snprintf(output, 32, "%s.%03d", buf, msec);
  if (ret == 0) {
    perror("snprintf fail");
  }

  std::cout << std::string(output) << std::endl;

  return 0;
}
