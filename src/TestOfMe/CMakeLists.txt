
#1. 确定CMake的最低版本需求
CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

#2. 确定工程名
PROJECT(WtTester LANGUAGES CXX)
SET(CMAKE_CXX_STANDARD 11)

# SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/build_${PLATFORM}/${CMAKE_BUILD_TYPE}/bin/WtBtRunner)
SET(MyDeps "/home/mydeps")
SET(INCS ${MyDeps}/include)
SET(LNKS ${MyDeps}/lib ${PROJECT_SOURCE_DIR}/../build_debug/build_x64/Release/libs)
INCLUDE_DIRECTORIES(${INCS})
LINK_DIRECTORIES(${LNKS})

SET(LIBS
	WtBtCore
	WTSTools
	WTSUtils
)

IF(MSVC)
ELSE(GNUCC)
	LIST(APPEND LIBS
		boost_filesystem
		pthread
		dl)
	if(WIN32)
		LIST(APPEND LIBS iconv)
	ENDIF()
ENDIF()

#添加源码
file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h)

#9. 生成可执行文件
ADD_EXECUTABLE(WtBtRunner ${SRCS} ${HDRS})
TARGET_LINK_LIBRARIES(WtBtRunner ${LIBS})

