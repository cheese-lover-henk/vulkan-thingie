cmake_minimum_required(VERSION 3.20)
project(Vulkan)

set(CMAKE_CXX_STANDARD 20)

add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Include paths
target_include_directories(${PROJECT_NAME} PRIVATE
	${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/vendor-libs/glm
	${CMAKE_SOURCE_DIR}/vendor-libs/imgui
    ${CMAKE_SOURCE_DIR}/vendor-libs/imgui/backends
	${CMAKE_SOURCE_DIR}/vendor-libs/stb
	${CMAKE_SOURCE_DIR}/vendor-libs/tinyobjloader
	${CMAKE_SOURCE_DIR}/vendor-libs/vk-bootstrap
	${CMAKE_SOURCE_DIR}/vendor-libs/vma
    ${CMAKE_SOURCE_DIR}/vendor-libs
)

target_compile_definitions(${PROJECT_NAME} PRIVATE FMT_HEADER_ONLY=1)

file(GLOB IMGUI_SRC
	vendor-libs/imgui/*.cpp
    vendor-libs/imgui/backends/imgui_impl_*.cpp
)
target_sources(${PROJECT_NAME} PRIVATE ${IMGUI_SRC})

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${Vulkan_LIBRARIES})

file(GLOB TINYOBJ_SRC vendor-libs/tinyobjloader/*.cc)
if(TINYOBJ_SRC)
	target_sources(${PROJECT_NAME} PRIVATE ${TINYOBJ_SRC})
endif()

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)