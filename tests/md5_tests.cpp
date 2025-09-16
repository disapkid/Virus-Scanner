#include <gtest/gtest.h>
#include <md5/md5.hpp>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

TEST(MD5, HashString_KnownVectors) {
    EXPECT_EQ(MD5::hashString(""),      "d41d8cd98f00b204e9800998ecf8427e");
    EXPECT_EQ(MD5::hashString("a"),     "0cc175b9c0f1b6a831c399e269772661");
    EXPECT_EQ(MD5::hashString("abc"),   "900150983cd24fb0d6963f7d28e17f72");
    EXPECT_EQ(MD5::hashString("message digest"), "f96b697d7cb7938d525a2f31aaf161d0");
    EXPECT_EQ(MD5::hashString("abcdefghijklmnopqrstuvwxyz"), "c3fcd3d76192e4007dfb496cca67e13b");
}

TEST(MD5, HashFile_SmallAndLarge) {
    fs::path tmp = fs::temp_directory_path() / "md5_small.txt";
    {
        std::ofstream f(tmp, std::ios::binary);
        f << "abc";
    }
    EXPECT_EQ(MD5::hashFile(tmp.string()), "900150983cd24fb0d6963f7d28e17f72");

    fs::path big = fs::temp_directory_path() / "md5_big.bin";
    {
        std::ofstream f(big, std::ios::binary);
        std::string chunk(8192 + 123, 'X'); 
        f.write(chunk.data(), (std::streamsize)chunk.size());
    }
    
    EXPECT_EQ(MD5::hashFile(big.string()), "e01c9cd7fe93da7ae6b8cfb76fed0259");

    EXPECT_EQ(MD5::hashFile((fs::temp_directory_path() / "does_not_exist.bin").string()), "");
}