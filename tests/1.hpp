/**
 * @file 1.hpp
 * @author Mohammed Ghaith Al-Mahdawi (Mohido)
 * @brief Tests basic YAML variables processing. 
 */

#include <iostream>
#include "../yaml/yaml.hpp"

namespace TINY_YAML{
namespace tests {

    #ifndef TINY_YAML_TESTS_HELPER_FUNCS
    #define TINY_YAML_TESTS_HELPER_FUNCS
        template<typename T>
        bool assert(T v1, T v2){
            bool result = v1 == v2;
            std::cout << "TEST: Value (" << v1 << ") Expected to be (" << v2 << ")? " << ((result)? "passed" : "failed") << std::endl;
            return result;
        }

        /// @brief - Mainly used in compile time to get the absolute path of .hpp/.cpp file parent directory
        /// @return - Directory absolutepath of the current file.
        std::string dirpath(){
            std::string hppfilepath(__FILE__);
            #if _WIN32
                return hppfilepath.substr(0, hppfilepath.find_last_of("\\"));
            #else 
                return hppfilepath.substr(0, hppfilepath.find_last_of("/"));
            #endif
        }
    #endif

    bool test_1_variables(){
        int passed = 0;
        int total = 0;
        std::cout << "############# TESTGROUP: test_variables" << std::endl;
        try{
            Yaml yamlFile( dirpath() + std::string("/1.yaml"));
            total++; passed += assert(yamlFile["version"].getData<std::string>(), std::string("1.2.3")); 
            total++; passed += assert(yamlFile["name"].getData<std::string>(), std::string("\"tiny yaml\""));
            total++; passed += assert(yamlFile["age"].getData<std::string>(), std::string("123"));
            total++; passed += assert(yamlFile["alive"].getData<std::string>(), std::string("true"));
            total++; passed += assert(yamlFile["complex_text"].getData<std::string>(), std::string("\"-1234he-\"")); 
            total++; passed += assert(yamlFile["comment_text"].getData<std::string>(), std::string("\"this is how to write a # comment\""));
            total++; passed += assert(yamlFile["var_comm"].getData<std::string>(), std::string("\"Some text\""));
            total++; passed += assert(yamlFile["special_text"].getData<std::string>(), std::string("\"Some#text\""));
        }catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
            return false;
        }
        std::cout << "-- TESTGROUP test_variables RESULT: " << passed << " passed out of " << total << std::endl;
        std::cout << "############################" << std::endl;
        return true;
    }

}}