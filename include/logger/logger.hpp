#include <iostream>
#include <atomic>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <vector>
#include "export.hpp"
#pragma once

class SCANNERLIB_API logger {
private:
	std::atomic<size_t> total_files_scanned;
	std::atomic<size_t> total_viruses_found;
	std::atomic<size_t> total_errors;
	std::string path;
public:
	logger() = default;

	void report(); 

	void logging(std::string path, std::string hash, std::string verdict); 

	void get_path(std::string p);

	bool check_path();

	void add_total_scanned();

	void add_total_errors();

	void add_viruses_found();
};