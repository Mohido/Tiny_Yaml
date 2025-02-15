# Tiny_Yaml
A powerful simple lightweight YAML parser library for C++. There are lots of libraries which parse yaml files in C++, yet they are cumbersome and very heavy to include 
in a performance-matter project, thus increasing the need for a minimal robust parser. This library is useful when you already know that the yaml file will NOT be changing Also, keep in mind that all values are returned as strings:

```
# example:
123 is represented as std::string("123") in C++

true is std::string("true")

"true" is std::string("\"true\"")
```

> This behavior will change in the future and support a better type-parsing (during yaml loadtime and not during application execution time). But for now, you should know parse the values to the type you need. 

### Features:
1. Very easy to integrate to your project:
    1. Copy the `yaml/` directory to your project.
    2. Include the `yaml.hpp` file in your source code.
    3. Add the `yaml.cpp` to the compiler and linker.

2. Robust and Recovery:
    * Simple indentation errors are recoverable. The parser will try its best to find the best suit for the yaml layout even if there are unconsistant indentations.
    * Abilty to parse list-elements and list-nodes. These happen when a parent node either has a list of nodes or elements attached to it. 
    
3. Simple to Use:
    * Retreiving values of nodes or lists are quite simple and intuitive. Note, the syntax is shown below.

---

### How to Use:
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
  TINY_YAML::Yaml coolYamlObject(<yaml_file_path>);
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
      
---

# Notes:
    - Contributions are welcome!
    - Bugs/Suggestions/Reports can be created as issues on Github with the desired label.
    - This library is still in development (which means it does not fully support all yaml features yet).
    - I am trying to add new features and fix bugs for features I use. If I don't use a feature, it won't be added soon. Therefore, if you need a feature, feel free to create an issue or a PR. Just make sure to follow the contribution guide.

# Issues:
  - Does not support all yaml specifications
  - Does not support multi-line strings
  - Does not support multiple yaml documents in a single file (`---`, `...` can cause bugs)
  - Using `#` in strings will be treated as a comment (even if surrounded by quotes)
  - Does not write yaml files (it only reads them)
  - Does not support `%` specification (e.g. `%YAML 1.2`)
  - Having '-' in a string will cause a bug
  - All values must be gotten as strings (by using `getData<string>()`) (even numbers and booleans must be gotten as strings and then casted dynamically)
    - e.g: `variable: ""` in yaml will return `"\"\""` value in C++

# Development

### VSCode

> NOTE: Only windows configuration is given in the `.vscode` directory. 
1. Install the C/C++ extension
2. Install CLANG compiler
3. Set the compiler path to `clang++` in `.vscode/c_cpp_properties.json` (incase you installed clang in a different path)
4. Go to the `Run and Debug` tab in the left side bar and click the `Run` button. This will run the `tests/main.cpp` (testing the package).

