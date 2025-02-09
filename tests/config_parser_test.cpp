#include "config_parser.hpp"
#include <gtest/gtest.h>

TEST(ConfigParserTest, ParseValidYAML){
    Config cfg = load_config("/home/yusuke/oss_dev/config_parser/tests/test_config.yaml");
    EXPECT_EQ(cfg.host, "localhost");
    EXPECT_EQ(cfg.port, 5432);
}

TEST(ConfigParserTest, MissingFile){
    EXPECT_THROW(load_config("non_existent.yaml"), std::runtime_error);
}

TEST(ConfigParserTest, DefaultValues){
    Config cfg = load_config("/home/yusuke/oss_dev/config_parser/tests/test_config_missing_keys.yaml");
    EXPECT_EQ(cfg.host, "127.0.0.1");
    EXPECT_EQ(cfg.port, 3306);
}

int main (int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}