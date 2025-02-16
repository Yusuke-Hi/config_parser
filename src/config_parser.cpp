#include "config_parser.hpp"

#include <fstream>
#include <iostream>

// ConfigParser::ConfigParser() {}
// ConfigParser::~ConfigParser() {}

void ConfigParser::load_config(const std::string& filename) {
  std::ifstream file(filename);
  if (!file) {
    throw std::runtime_error("Error: Config file '" + filename + "' not found.");
  }

  YAML::Node yaml_config = YAML::LoadFile(filename);

  config.host = yaml_config["database"]["host"] ? yaml_config["database"]["host"].as<std::string>()
                                                : "127.0.0.1";
  config.port = yaml_config["database"]["port"] ? yaml_config["database"]["port"].as<int>() : 3306;
}

Config ConfigParser::getConfig() const { return config; }