#ifndef CONFIG_PARSER_
#define CONFIG_PARSER_

#include <yaml-cpp/yaml.h>

#include <string>

struct Config {
  std::string host;
  int port;
};

class ConfigParser {
 public:
  ConfigParser(){};
  ~ConfigParser(){};
  void load_config(const std::string& filename);
  Config getConfig() const;
  void validate_config();

 private:
  Config config;
};

#endif