#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <unordered_map>

class Database
{
public:
    Database()
    {
        // data members
    }

    void insert(const std::string& key, const std::string& value)
    {
        // Insert a key-value pair into the database
        data[key] = value;
    }

    std::string retrieve(const std::string& key)
    {
        // Retrieve the value for a given key from the database
        return data[key];
    }

private:
    std::unordered_map<std::string, std::string> data;
};
#pragma once
