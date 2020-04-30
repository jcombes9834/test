#include <iostream>
#include <ctime>
#include <math.h>
#include <thread>

using namespace std;


bool is_prime(unsigned long int num);
void primes(int max_seconds, int i);

int main()
{
  thread myThread(primes, 10, 2);
  thread myThread1(primes, 11, 2);
  thread myThread2(primes, 12, 2);
  thread myThread3(primes, 13, 2);
  thread myThread4(primes, 14, 2);
  thread myThread5(primes, 15, 2);
  thread myThread6(primes, 16, 2);
  thread myThread7(primes, 17, 2);
  myThread.join();
  myThread1.join();
  myThread2.join();
  myThread3.join();
  myThread4.join();
  myThread5.join();
  myThread6.join();
  myThread7.join();
  
  return 0;
}



void primes(int max_seconds, int i)
{
  double found = 0;
  cout << "Starting!" << endl;
  time_t start;
  start = time(NULL);
while(1){
  if (is_prime(i))
  {
    found++;
   // cout << "found one!" << endl;
  }

  int running_seconds = (time(NULL) - start);

  if (running_seconds >= max_seconds)
  {
    cout << "Found " << found << " primes in " << max_seconds << " seconds" << endl;
    return;
  }

  i++;
}
}

bool is_prime(unsigned long int num)
{
  // Only have to check for divisible for the sqrt(number)
  int upper = sqrt(num);

  // Check if the number is evenly divisible (start at 2 going up)
  for (unsigned long int cnum = 2; cnum <= upper; cnum++)
  {
    unsigned long int mod = num % cnum; // Remainder

    if (mod == 0)
    {
      return 0;
    } // If the remainer is 0 it's evenly divisible
  }

  return 1; // If you get this far it's prime
}