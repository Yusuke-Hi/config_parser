#include "config_parser.hpp"

#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

int main(){
    std::string config_path = "/home/yusuke/oss_dev/config_parser/config.yaml";
    // file check
    try{
        Config cfg = load_config(config_path);
        std::cout << "Database Host: " << cfg.host << std::endl;
        std::cout << "Database Port: " << cfg.port << std::endl;
    }catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return 1;
    }
}