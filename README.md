# Config Parser

## Overview

A simple C++ library for parsing configuration files in YAML format.

## Features
- Reads configuration files in YAML format
- Provides default values for missing configuration options
- Supports structured configuration with nested keys

## Requirements
- C++17 or later
- CMake 3.10 or later
- yaml-cpp
- Google Test (for testing)

## Installation
```
mkdir build
cd build
cmake ..
make
```

## Usage
```
#include "config_parser.hpp"

int main() {
    Config cfg = load_config("config.yaml");
    std::cout << "Database Host: " << cfg.host << std::endl;
    std::cout << "Database Port: " << cfg.port << std::endl;
    return 0;
}
```

## Running Tests
```
cd build
ctest --output-on-failure
```

## License

MIT License