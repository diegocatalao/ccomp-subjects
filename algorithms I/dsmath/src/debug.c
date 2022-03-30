#include "debug.h"

void __print_str_datetime(char *s_message) {
	char str_datetime[64];
	time_t timer = time(NULL);
	struct tm *s_timer = localtime(&timer);
	strftime(str_datetime, sizeof(str_datetime), "%c", s_timer);
	printf("%s%s\n", s_message, str_datetime);
}

void debug_ftime(char* fname, void (*function)(void)) {
	double seconds, microseconds;
	struct timeval start_time, finish_time;

	printf("======================================== %s ========================================\n", fname);
	__print_str_datetime("Started at: ");
	
	gettimeofday(&start_time, NULL);
	(*function)();
	gettimeofday(&finish_time, NULL);
	seconds = (finish_time.tv_sec - start_time.tv_sec);
	microseconds = ((seconds * 1000000) + finish_time.tv_usec) - (start_time.tv_usec);

	__print_str_datetime("Finished at: ");
	printf("Execution time in seconds: %1.fs\n", seconds);
	printf("Execution time in microseconds: %1.fμs\n", microseconds);
}