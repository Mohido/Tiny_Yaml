/**
 * @file 3.hpp
 * @author Mohammed Ghaith Al-Mahdawi (Mohido)
 * @brief Tests list type
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
 
     bool test_3_basic_list(){
         int passed = 0;
         int total = 0;
         std::cout << "############# TESTGROUP: test_basic_list" << std::endl;
         try{
             Yaml yamlFile( dirpath() + std::string("/3.yaml"));
             total++; passed += assert(yamlFile["list"].getData<std::vector<std::string>>().size(), std::size_t(3)); 
             total++; passed += assert(yamlFile["list"].getData<std::vector<std::string>>()[0], std::string("item1")); 
             total++; passed += assert(yamlFile["list"].getData<std::vector<std::string>>()[1], std::string("item2")); 
             total++; passed += assert(yamlFile["list"].getData<std::vector<std::string>>()[2], std::string("item3")); 
         }catch(const std::exception& e){
             std::cerr << e.what() << std::endl;
             return false;
         }
         std::cout << "-- TESTGROUP test_basic_list RESULT: " << passed << " passed out of " << total << std::endl;
         std::cout << "############################" << std::endl;
         return true;
     }
 }}