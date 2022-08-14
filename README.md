# Tiny_Yaml
A powerful simple lightweight YAML parser library for C++. There are lots of libraries which parse yaml files in C++, yet they are cumbersome and very heavy to include 
in a performance-matter project, thus increasing the need for a minimal robust parser. 

## Features
1. Very easy to integrate to your project:
    1. Copy the `yaml/` directory to your project.
    2. Include the `yaml.hpp` file in your source code.
    3. Add the `yaml.cpp` to the compiler and linker.

2. Robust and Recovery:
    * Simple indentation errors are recoverable. The parser will try its best to find the best suit for the yaml layout even if there are unconsistant indentations.
    * Abilty to parse list-elements and list-nodes. These happen when a parent node either has a list of nodes or elements attached to it. 
    
3. Simple to Use:
    * Retreiving values of nodes or lists are quite simple and intuitive. Note, the syntax is shown below.


## How to Use:
The content below represents a yaml file, then a set of examples on how to extract the data:

> `example.yaml`
```
 object:					
   name: "mohido"			
   property: "cool as hell"
 							
 version: 123				
 academy: "333"			
 							
 list:						
   - item1					
   - item2					
   - item3					
 							
 node_list: 				
   - name : "node1"		
     value: 1				
     hell:					
       - item1: "sang"		
       - item1: "mang"		
   - name : "node2"		
     value: 2				
     temp: extra			
     extra:				
       - extra1			
       - extra2			
       - extra3			
```
First of all, create a yaml parser object:
  ```
  YAML::Yaml coolYamlObject(<yaml_file_path>);
  ```
  
 -	value `"mohido"` of `object.name` can be accessed as follows:
      ```
      coolYamlObject["object"]["name"].getData<std::string>();
      ```

 - value `123` of `version` can be accessed as follows:
      ```
      coolYamlObject["version"].getData<std::string>();
      ```

 - value `item1` of `list[0]` can be accessed as follows:
      ```
      coolYamlObject["list"].getData<std::vector<std::string>>()[0];
      ```

 - value `"node1"` of `node_list[0].name` can be accessed as follows:
      ```
      coolYamlObject["node_list"]["0"]["name"].getData<std::string>();
      ```

 - value `extra3` of `node_list[1].extra[2]` can be accessed as follows:
      ```
      coolYamlObject["node_list"]["1"]["extra"].getData<std::vector<std::string>>()[2];
      ```



