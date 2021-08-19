# Install script for directory: /media/sf_nos3/fsw/cfe

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/media/sf_nos3/fsw/build/exe")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "debug")
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
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cpu1/cf" TYPE FILE RENAME "cfe_es_startup.scr" FILES "/media/sf_nos3/fsw/nos3_defs/cfe_es_startup.scr")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/media/sf_nos3/fsw/build/cpu1/osal/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/psp/nos-linux/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/cfs_lib/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/hwlib/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/io_lib/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/ci/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/hk/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/hs/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/lc/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/sc/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/sch/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/to/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/sample/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/novatel_oem615/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/arducam/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/clyde_eps/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/apps/generic_reaction_wheel/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/cfe_core_default_cpu1/cmake_install.cmake")
  include("/media/sf_nos3/fsw/build/cpu1/cpu1/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/media/sf_nos3/fsw/build/cpu1/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
