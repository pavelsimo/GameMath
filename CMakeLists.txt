PROJECT(GameEngine)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(GTest REQUIRED)
INCLUDE_DIRECTORIES(${GTEST_INCLUDE_DIRS})

INCLUDE(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        MESSAGE(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()



ADD_LIBRARY(
   GameMath SHARED
   src/MathUtilities.cpp 
   src/Vector2.cpp
   src/AABB2.cpp 
   src/Sphere2.cpp
   src/Ray2.cpp
)

ADD_EXECUTABLE(
   Test 
   src/test/Test.cpp
   src/MathUtilities.cpp 
   src/Vector2.cpp
   src/AABB2.cpp 
   src/Sphere2.cpp
   src/Ray2.cpp
)

TARGET_LINK_LIBRARIES(Test ${GTEST_LIBRARIES} pthread)

