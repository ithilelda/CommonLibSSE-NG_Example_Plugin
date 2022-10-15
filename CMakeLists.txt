cmake_minimum_required(VERSION 3.24)

# set the project name, version and language.
project(example VERSION 1.0.0 LANGUAGES CXX)

# configure the version file so that your dll will have extra info.
configure_file(cmake/version.rc.in version.rc @ONLY)

# set the headers and sources variable, so that they could later be used by add_commonlibsse_plugin.
# if you have more headers/sources, just add a line after the example file.
set(headers
        src/plugin.hpp
)

set(sources
        src/main.cpp

        ${CMAKE_CURRENT_BINARY_DIR}/version.rc
)


# CommonLibSSE-NG simplifies the process of making a plugin. do this according to the official doc.
find_package(CommonLibSSE REQUIRED)
add_commonlibsse_plugin(${PROJECT_NAME} SOURCES ${headers} ${sources})

# add the pch.h precompile header. it contains includes without which CommonLibSSE-NG will not compile.
target_precompile_headers(${PROJECT_NAME}
        PRIVATE
        src/pch.h)


		
# after compilation, we copy the dll file to the plugins directory of skse in skyrim's data folder.
add_custom_command(
	TARGET "${PROJECT_NAME}"
	POST_BUILD
	COMMAND "${CMAKE_COMMAND}" -E copy_if_different "$<TARGET_FILE:${PROJECT_NAME}>" "$ENV{SKYRIM_SKSE64_PLUGIN_DIR}"
	VERBATIM
)