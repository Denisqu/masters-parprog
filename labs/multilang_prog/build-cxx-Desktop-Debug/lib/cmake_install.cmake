# Install script for directory: /home/user/univer/homework_and_labs/labs/multilang_prog/cxx/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/external/vector_class_lib/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/shared/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/singlethreaded_nonvectorized/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/singlethreaded_nonvectorized_optimized/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/singlethreaded_vectorized_optimized/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/singlethreaded_vectorized_aligned_optimized/cmake_install.cmake")
  include("/home/user/univer/homework_and_labs/labs/multilang_prog/build-cxx-Desktop-Debug/lib/multithreaded_vectorized_aligned_optimized/cmake_install.cmake")

endif()

