#include <gtest/gtest.h>
#include <parser/parser.hpp>
#include <scanner/scanner.hpp>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

TEST(Parser, CsvParse_ValidAndMalformedLines) {
    fs::path csv = fs::temp_directory_path() / "base.csv";
    {
        std::ofstream f(csv);
        f << "a9963513d093ffb2bc7ceb9807771ad4;Exploit\n";
        f << "ac6204ffeb36d2320e52f1d551cfa370;Dropper\n";
        f << "MALFORMED_LINE_WITHOUT_DELIMETER\n";
        f << "8ee70903f43b227eeb971262268af5a8;Downloader\n";
        f << ";MissingHash\n";
        f << "deadbeef;   Verdict With Spaces   \n";
        f << "   \n";
    }

    parser p;
    auto map = p.csv_parse(csv.string());
    ASSERT_EQ(map.count("a9963513d093ffb2bc7ceb9807771ad4"), 1u);
    ASSERT_EQ(map.count("ac6204ffeb36d2320e52f1d551cfa370"), 1u);
    ASSERT_EQ(map.count("8ee70903f43b227eeb971262268af5a8"), 1u);

    EXPECT_EQ(map.count("MALFORMED_LINE_WITHOUT_DELIMETER"), 0u);
    EXPECT_EQ(map.count(""), 0u);
    ASSERT_EQ(map.count("deadbeef"), 1u);
    EXPECT_EQ(map["deadbeef"], "   Verdict With Spaces   ");
}

TEST(Parser, CommandParse_FillsScannerFields) {
    fs::path csv = fs::temp_directory_path() / "cmd_base.csv";
    fs::path log = fs::temp_directory_path() / "cmd_report.log";
    fs::path path = fs::temp_directory_path(); 

    {
        std::ofstream f(csv);
        f << "900150983cd24fb0d6963f7d28e17f72;TestVerdict\n"; 
    }

    scanner sc;
    parser p;

    std::string a0 = "scanner.exe";
    std::string a1 = "--base"; std::string a2 = csv.string();
    std::string a3 = "--log";  std::string a4 = log.string();
    std::string a5 = "--path"; std::string a6 = path.string();

    const char* argv[] = { a0.c_str(), a1.c_str(), a2.c_str(), a3.c_str(), a4.c_str(), a5.c_str(), a6.c_str() };
    p.command_parse(7, const_cast<char**>(argv), sc);
}