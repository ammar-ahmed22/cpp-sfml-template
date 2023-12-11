cmake_minimum_required(VERSION 3.10)
project(Project VERSION 1.0.0 LANGUAGES CXX)

# Default to release builds
if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE Release)
endif()

# Finds the SMFL library
find_package(SFML 2 REQUIRED COMPONENTS graphics system window)

# sets variable SMFL_LBS = sfml-graphics, sfml-system, smfl-window
set(SFML_LIBS sfml-graphics sfml-system sfml-window)

# Sets glob file(s) to variable SOURCES
file(GLOB SOURCES **/*.cpp)

# Adds an executable with the PROJECT_NAME from SOURCES file
add_executable(${PROJECT_NAME} ${WIN32_GUI} ${SOURCES} ${RESOURCE_FILES})

# Includes the directories
target_include_directories(${PROJECT_NAME} PRIVATE "include/headers")

# Copy resources dir to output
file(COPY "resources" DESTINATION ${CMAKE_BINARY_DIR})

# Sets SMFL_LIBS = sfml-graphics, sfml-system, smfl-window
set(SFML_LIBS sfml-system sfml-window sfml-graphics)

# Links the libraries to the project
target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})

# Sets the C++ version
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# For unix systems, adds pthread library
if (UNIX)
   target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)

# For Visual C++ (Visual Studio etc.)
if(MSVC)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
   endforeach()
endif()