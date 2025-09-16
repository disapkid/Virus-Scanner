#include <scanner/scanner.hpp>
#include <parser/parser.hpp>
#include <iostream>
#include <chrono>

int main(int argc, char* argv[]) {
	scanner scan;
	parser parse;
	parse.command_parse(argc, argv, scan);
	if (scan.check_path_base() && scan.log.check_path()) {

		auto time_start = std::chrono::high_resolution_clock::now();
		scan.scan_directory("");
		scan.log.report();

		auto time_end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start).count();

		std::cout << "Runtime: " << duration << "ms" << std::endl;
	}
	else {
		std::cout << "Incorrect input command" << std::endl;
	}
	return 0;
}