#include "config_parser.hpp"

#include <gtest/gtest.h>

TEST(ConfigParserTest, ParseValidYAML) {
  ConfigParser config_parser;
  config_parser.load_config("../tests/test_config.yaml");
  Config cfg = config_parser.getConfig();
  EXPECT_EQ(cfg.host, "localhost");
  EXPECT_EQ(cfg.port, 5432);
}

TEST(ConfigParserTest, MissingFile) {
  ConfigParser config_parser;
  EXPECT_THROW(config_parser.load_config("non_existent.yaml"), std::runtime_error);
}

TEST(ConfigParserTest, BadConversion) {
    ConfigParser config_parser;
  EXPECT_THROW(config_parser.load_config("../tests/test_config_badtypeconversion.yaml"), std::runtime_error);
}

TEST(ConfigParserTest, DefaultValues) {
  ConfigParser config_parser;
  config_parser.load_config("../tests/test_config_missing_keys.yaml");
  Config cfg = config_parser.getConfig();
  EXPECT_EQ(cfg.host, "127.0.0.1");
  EXPECT_EQ(cfg.port, 3306);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}