#include "config_parser.hpp"
#include <iostream>
#include <fstream>

Config load_config(const std::string& filename){
    std::ifstream file(filename);
    if (!file){
        throw std::runtime_error("Error: Config file '" + filename + "' not found.");
    }

    YAML::Node config = YAML::LoadFile(filename);

    Config cfg;
    cfg.host = config["database"]["host"] ? 
        config["database"]["host"].as<std::string>(): "127.0.0.1";
    cfg.port = config["database"]["port"] ?
        config["database"]["host"].as<int>(): 3306;

    return cfg;
}