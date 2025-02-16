#include "config_parser.hpp"

#include <fstream>
#include <iostream>

void ConfigParser::load_config(const std::string& filename) {
  std::ifstream file(filename);
  if (!file) {
    throw std::runtime_error("Error: Config file '" + filename + "' not found.");
  }

  try{
  YAML::Node yaml_config = YAML::LoadFile(filename);
  config.host = yaml_config["database"]["host"] ? yaml_config["database"]["host"].as<std::string>()
                                                : "127.0.0.1";
  config.port = yaml_config["database"]["port"] ? yaml_config["database"]["port"].as<int>() : 3306;
  } catch(const YAML::BadFile& e){
    throw std::runtime_error("Error: Failed to read config file '" + filename + "'not found.");
  } catch(const YAML::BadConversion& e){
    throw std::runtime_error("Error: Type conversion error in config file '" + filename + "'.");
  } catch(const YAML::Exception& e){
    throw std::runtime_error("Error: YAML parsing error in file '" + filename + "': " + e.what());
  }
}

Config ConfigParser::getConfig() const { return config; }

void ConfigParser::validate_config(){
  if (config.port < 0 || 65535 < config.port){
    throw std::runtime_error("Error: Port number out of valid range(0-65535)");
  }
  if (config.host.empty()){
    throw std::runtime_error("Error: Missing required field 'host'");
  }
}

