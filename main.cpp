#include "main.hpp"
#include <iostream>
#include "osm.cpp"
#include "osm.h"

int main() {
	std::cout << osm_operation_time(100000) << '\n';
	std::cout <<osm_function_time(100000) << '\n';
	std::cout << osm_syscall_time(100000) << '\n';
};