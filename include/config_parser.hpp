#ifndef CONFIG_PARSER_
#define CONFIG_PARSER_

#include <string>
#include <yaml-cpp/yaml.h>

struct Config{
    std::string host;
    int port;
};

Config load_config(const std::string& filename);

#endif