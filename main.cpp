#include "osm.cpp"
#include <iostream>



int main() {
	std::cout << osm_operation_time(100000) << '\n';
	std::cout <<osm_function_time(100000) << '\n';
	std::cout << osm_syscall_time(100000) << '\n';
};