#include <gtest/gtest.h>
#include <logger/logger.hpp>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>

namespace fs = std::filesystem;

TEST(Logger, LoggingAndCounters) {
    fs::path log_path = fs::temp_directory_path() / "scanner_log.txt";

    if (fs::exists(log_path)) fs::remove(log_path);

    logger lg;
    lg.get_path(log_path.string());
    EXPECT_FALSE(lg.check_path());

    lg.logging("C:/path/to/file.exe", "deadbeef", "Exploit");
    lg.logging("C:/path/to/another.dll", "cafebabe", "Dropper");

    lg.add_total_scanned();
    lg.add_total_scanned();
    lg.add_viruses_found();
    lg.add_total_errors();

    ASSERT_TRUE(fs::exists(log_path));
    std::ifstream in(log_path);
    std::string all((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
    EXPECT_NE(all.find("C:/path/to/file.exe"), std::string::npos);
    EXPECT_NE(all.find("deadbeef"), std::string::npos);
    EXPECT_NE(all.find("Exploit"), std::string::npos);
    EXPECT_NE(all.find("C:/path/to/another.dll"), std::string::npos);
    EXPECT_NE(all.find("cafebabe"), std::string::npos);
    EXPECT_NE(all.find("Dropper"), std::string::npos);

    std::ostringstream oss;
    auto* oldbuf = std::cout.rdbuf(oss.rdbuf());
    lg.report();
    std::cout.rdbuf(oldbuf);

    std::string out = oss.str();
    EXPECT_NE(out.find("Total files scanned"), std::string::npos);
    EXPECT_NE(out.find("Total viruses found"), std::string::npos);
    EXPECT_NE(out.find("Total errors"), std::string::npos);
}