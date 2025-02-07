#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

int main(){
    std::string config_path = "/home/yusuke/oss_dev/config_parser/config.yaml";
    // file check
    std::ifstream file(config_path);
    if (!file){
        std::cerr << "Error: Config file '" << config_path << "' not found." << std::endl;
        return 1;
    }

    // load yaml
    YAML::Node config;
    try{
        config = YAML::LoadFile(config_path);
    }catch (const YAML::Exception &e){
        std::cerr << "Error: Failed to parse YAML file: " << e.what() << std::endl;
        return 1;
    }

    // get data and set default
    std::string host = config["database"]["host"] ?
        config["database"]["host"].as<std::string>() : "127.0.0.1";
    int port = config["database"]["port"] ? 
        config["database"]["port"].as<int>() : 3306;

    // print
    std::cout << "Database Host : " << host << std::endl;
    std::cout << "Database Port : " << port << std::endl;
}