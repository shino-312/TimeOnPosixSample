#include <iostream>
#include <cassert>
#include <ctime>

int main(void) {

  struct timespec ts;

  // Success: Returns 0
  // Failure: Returns -1
  // First arg: CLOCK_REALTIME, CLOCL_MONOTONIC, etc.
  int ret = clock_gettime(CLOCK_REALTIME, &ts);
  assert(ret == 0);

  std::cout << "Seconds       : " << ts.tv_sec  << std::endl
            << "Nano seconds  : " << ts.tv_nsec << std::endl;
  // Seconds       : 1559985934
  // Nano seconds  : 113947957

  return 0;
}
