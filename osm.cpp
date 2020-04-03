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

double timeval_to_nano(timeval time_obj){
	return time_obj.tv_sec * pow(10,9) + time_obj.tv_usec * pow(10,3);
}

/* Time measurement function for a simple arithmetic operation.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_operation_time(unsigned int iterations)
{
	timeval start_time, end_time;
	int retval;
	double diff;
	unsigned int var = 0;

	retval = gettimeofday(&start_time, NULL);
	if (retval == -1 or iterations == 0)
	{
		return -1;
	}

	for (unsigned int i = 0; i < iterations;)
	{
		i += 1;
		i += 1;
		i += 1;
		i += 1;
		i += 1;
	}

	retval = gettimeofday(&end_time, NULL);
	if (retval != -1)
	{

		diff = timeval_to_nano(end_time) - timeval_to_nano(start_time);
		return diff / iterations;
	}
	return -1;
}


/* Time measurement function for an empty function call.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_function_time(unsigned int iterations)
{
	timeval start_time, end_time;
	int retval;
	double diff ;

	retval = gettimeofday(&start_time, NULL);
	if (retval == -1 or iterations == 0)
	{
		return -1;
	}

	for (unsigned int i = 0; i < iterations; i=i+5)
	{
		empty_function();
		empty_function();
		empty_function();
		empty_function();
		empty_function();
	}
	retval = gettimeofday(&end_time, NULL);
	if (retval != -1)
	{
		diff = timeval_to_nano(end_time) - timeval_to_nano(start_time);
		return diff / iterations;
	}
	return -1;
}


/* Time measurement function for an empty trap into the operating system.
   returns time in nano-seconds upon success,
   and -1 upon failure.
   */
double osm_syscall_time(unsigned int iterations)
{

	timeval start_time, end_time;
	double diff;
	int retval;
	retval = gettimeofday(&start_time, NULL);
	if (retval == -1 or iterations == 0)
	{
		return -1;
	}

	for (unsigned int i = 0; i < iterations; i=i+5)
	{
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
		OSM_NULLSYSCALL;
	}
	retval = gettimeofday(&end_time, NULL);
	if (retval != -1)
	{
		diff = timeval_to_nano(end_time) - timeval_to_nano(start_time);
		return diff / iterations;
	}
	return -1;
}
