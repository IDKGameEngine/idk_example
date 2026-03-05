cmake_minimum_required(VERSION 3.5)

project(idk_example VERSION 0.0.1)
add_compile_options(-Werror -Wall -Wextra)

add_subdirectory(libidk)
add_subdirectory(idk_gfx)
add_subdirectory(idk_core)

# configure_file(
#     "${PROJECT_SOURCE_DIR}/version.h.in"
#     "${PROJECT_BINARY_DIR}/version.h"
# )

add_executable(
    ${PROJECT_NAME} "main.cpp"
)
target_compile_features(
    ${PROJECT_NAME} PUBLIC cxx_std_23
)
target_link_libraries(
    ${PROJECT_NAME} PUBLIC idk_platform idk_gfx
)