#ifndef CONFIG_PARSER_
#define CONFIG_PARSER_

#include <string>
#include <yaml-cpp/yaml.h>

struct Config{
    std::string host;
    int port;
};

class ConfigParser{
    public:
        ConfigParser() {};
        ~ConfigParser() {};
        void load_config(const std::string& filename);
        Config getConfig() const;
    private:
        Config config;
};

#endif