#include <iostream>
#include <ctime>
#include <cassert>

int main(void) {

  struct timespec ts;
  struct tm t;

  int ret = clock_gettime(CLOCK_REALTIME, &ts);
  assert(ret == 0);

  // No error return
  localtime_r(&ts.tv_sec, &t);

  std::cout << "Year   : " << t.tm_year + 1900 << std::endl  // See definition of tm
            << "Month  : " << t.tm_mon  + 1    << std::endl  // See definition of tm
            << "Day    : " << t.tm_mday        << std::endl
            << "Hour   : " << t.tm_hour        << std::endl
            << "Minute : " << t.tm_min         << std::endl
            << "Second : " << t.tm_sec         << std::endl;

  char buf[32];
  int r = strftime(buf, 32, "%Y/%m/%d %H:%M:%S", &t);
  assert(r > 0);

  std::cout << std::string(buf) << std::endl;

  return 0;
}
