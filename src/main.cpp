#include <yaml-cpp/yaml.h>

#include <fstream>
#include <iostream>

#include "config_parser.hpp"

int main() {
  std::string config_path = "/home/yusuke/oss_dev/config_parser/config.yaml";
  // file check
  try {
    ConfigParser config_parser;
    config_parser.load_config(config_path);
    Config cfg = config_parser.getConfig();
    std::cout << "Database Host: " << cfg.host << std::endl;
    std::cout << "Database Port: " << cfg.port << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}