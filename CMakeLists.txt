cmake_minimum_required(VERSION 3.5)

project(idk_example VERSION 0.0.1)
add_compile_options(-Werror -Wall -Wextra)

add_executable(
    ${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)
target_compile_features(
    ${PROJECT_NAME} PUBLIC cxx_std_23
)
target_link_libraries(
    ${PROJECT_NAME} PRIVATE idk_core idk_gfx idk_platform
)
