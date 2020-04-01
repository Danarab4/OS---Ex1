#include "osm.h"
#include <sys/time.h>
#include <iostream>
#include <cmath>


/*
 * This is an empty function that does nothing at all
 */
void empty_function()
{
}

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
	unsigned int var = 0;
	while (var < iterations)
	{
		var += 1;
		var += 1;
		var += 1;
		var += 1;
		var += 1;
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
	timeval curr_time;
	int retval;
	retval = gettimeofday(&curr_time, NULL);
	if (retval == -1 or iterations == 0)
	{
		return -1;
	}
	double t1 = curr_time.tv_usec;
	iterations = iterations / 5;
	for (unsigned int i = 0; i < iterations; ++i)
	{
		empty_function();
		empty_function();
		empty_function();
		empty_function();
		empty_function();
	}
	retval = gettimeofday(&curr_time, NULL);
	double t2 = curr_time.tv_usec;
	if (retval != -1)
	{
		return ((t2 - t1) / iterations) * pow(10,9);
	}
	return -1;
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations)
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
	for (unsigned int i = 0; i < iterations; ++i)
	{
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
	}
	retval = gettimeofday(&curr_time, NULL);
	double t2 = curr_time.tv_usec;
	if (retval != -1)
	{
		return ((t2 - t1) / iterations) * pow(10,9);
	}
	return -1;
}
