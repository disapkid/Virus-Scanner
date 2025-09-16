#include "export.hpp"
#include <string>
#include <logger/logger.hpp>
#include <md5/md5.hpp>
#include <scanner/scanner.hpp>
#pragma once

class SCANNERLIB_API parser {
public:
	parser() = default;

	std::unordered_map<std::string, std::string> csv_parse(std::string path);

	void command_parse(int s, char* v[], scanner& sc);
};