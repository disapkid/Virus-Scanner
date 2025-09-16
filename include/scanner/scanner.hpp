#pragma once
#include <string>
#include <md5/md5.hpp>
#include <logger/logger.hpp>
#include <iostream>
#include <filesystem>
#include <future>
#include <thread>
#include <atomic>
#include "export.hpp"


class SCANNERLIB_API scanner {
private:
	std::unordered_map<std::string, std::string> csv_base;
	std::string path;
	static std::atomic<int> active_threads;
	static int hw_thread;
public:
	scanner() = default;

	MD5 md5hash;

	logger log;

	void get_csv_base(std::unordered_map<std::string, std::string> b);

	void get_path(std::string p);

	bool check_path_base();
	
	void scan_directory(std::string path_to_check);
};
