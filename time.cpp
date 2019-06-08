#include <iostream>
#include <ctime>

int main(void) {
  time_t t;

  // Sucess : Returns epoch time
  // Faliure: Returns -1
  t = time(NULL);

  std::cout << "Return: " << t   << std::endl;
  // Return: 1559983942

  return 0;
}
