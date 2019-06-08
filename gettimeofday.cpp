#include <iostream>
#include <cassert>
#include <sys/time.h>

int main(void) {

  struct timeval tv;

  // Success: Returns 0
  // Failure: Returns -1
  // Second arg should be always NULL (see man page)
  int ret = gettimeofday(&tv, NULL);
  assert(ret == 0);

  std::cout << "Seconds       : " << tv.tv_sec  << std::endl
            << "Micro seconds : " << tv.tv_usec << std::endl;
  // Seconds       : 1559984525
  // Micro seconds : 593563

  return 0;
}
