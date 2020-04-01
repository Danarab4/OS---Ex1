#include "osm.h"
#include <sys/time.h>
#include <iostream>
#include <cmath>

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations)
{
	timeval curr_time;
	int retval;
	retval = gettimeofday(&curr_time, NULL);
	if (retval == -1 or iterations == 0)
	{
		return -1;
	}
	double t1 = curr_time.tv_usec;
	iterations = iterations / 5;
	int var;
	for (int i = 0; i < iterations; ++i)
	{
		var = i + i;
		var = i + i;
		var = i + i;
		var = i + i;
		var = i + i;
	}
	retval = gettimeofday(&curr_time, NULL);
	double t2 = curr_time.tv_usec;
	if (retval != -1)
	{
		return ((t2 - t1) / iterations) * pow(10,9);
	}
	return -1;
}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations)
{
	return 1;
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations)
{
	return 1;
}

//int main() {
//	std::cout << osm_operation_time(10000000);
//	return 1;
////	std::cout  << "1" ;
//};