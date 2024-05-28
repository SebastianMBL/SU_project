cmake_minimum_required(VERSION 3.14)

project(SU LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Quick Sql)
if(NOT Qt5_FOUND)
    message(FATAL_ERROR "Qt5 not found! Please install Qt5.")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(SU
  main.cpp
  include.h include.cpp
  hero.h hero.cpp
  database.h database.cpp
  opponent.h opponent.cpp

)
target_link_libraries(SU Qt${QT_VERSION_MAJOR}::Core)

target_link_libraries(SU Qt5::Core Qt5::Quick Qt5::Sql)

include(GNUInstallDirs)
install(TARGETS SU
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
