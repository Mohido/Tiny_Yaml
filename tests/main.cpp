#include "1.hpp"    // Tests yaml variables 
#include "2.hpp"    // Test yaml objects
#include "3.hpp"    // Test yaml lists
#include "4.hpp"    // Test yaml object lists
#include "5.hpp"    // Test yaml nested complex object


int main(int argc, char** argv) {
    TINY_YAML::tests::test_1_variables();
    TINY_YAML::tests::test_2_basic_object();
    TINY_YAML::tests::test_3_basic_list();
    TINY_YAML::tests::test_4_basic_object_list();
    TINY_YAML::tests::test_5_complex_nested_object();
    return 0;
}