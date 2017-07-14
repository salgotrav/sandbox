## CMake

CMake is an Open Source tool to build C/C++ project on any platform. 
CMake generates build pipeline for the platform, which is then used to build the project.
The build pipeline can be Visual Studio Project file (.sln) or a Unix Style Makefile.

To use CMake, a CMakeLists.txt file is required in the project. This file contains all the build instructions. 
A simple way to build a project is to create a new directory named build. From the build directory, execute *cmake ..*  
This will generate a build pipeline. For the sake of simplicity, let's assume we are on a linux machine, and the build pipeline generated is a Makefile.
Generating build pipeline in a seperate build directory have the advantage of seperating the build files from project source files. 
All the build artifacts are in this directory, and can be deleted for cleanup.

The most basic CMake for a project is:
```
cmake_minimum_required(VERSION 2.9)
project(BasicProject)
add_executable(BasicProject, main.cpp)
```

Below is a sample CMakeLists.txt
* * *

Running Cmake with -p runs the script but don't generate a pipeline.

CMake is more like a scripting language and is very flexible. Let's go over the basic building blocks of CMake Scripting.

### message
```message("Building Core library.")```
message prints the message. Very useful for printing status messages.

### Variables
Every varible in CMake is a string. A variable is reference by specifying the name of variable in ${}. This is also known as variable reference.
Variables can be set by:
* Set command
  ```set (Number, 42) ```
  This sets the variable Number to 42.
  The statement message("The Ultimate Answer is ${Number}") prints *The Ultimate Answer is 42*.
* Varibles can be defined on command line 
  ```$ cmake -DNumber 42```
Quotes around arguments are optional as long as there are no spaces or reference variable.

### Including Scripts
  *include* command is used to add CMakeLists.txt from other directories. 
  *add_subdirectory* creates a new scope and executes the CMakeLists.txt from the subdirectory.

### Include Directories
  To set up the include directories *include_directories(directoryName)* is used.
  
### Targets
  *add_executable*, *add_target_library*, *add_custom_target* commands defines targets.
  
