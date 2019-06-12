configure_file(config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED system)

add_executable(join_server main.cpp)

add_library(utils version.cpp)
add_library(server server.cpp session.cpp)

set_target_properties(join_server utils server PROPERTIES
   CXX_STANDARD 14
   CXX_STANDARD_REQUIRED ON
   COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(join_server utils ${Boost_SYSTEM_LIBRARY})
target_link_libraries(join_server Threads::Threads)
target_link_libraries(join_server server)
target_include_directories(join_server INTERFACE ${Boost_INCLUDE_DIR})
target_include_directories(join_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(join_server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS join_server RUNTIME DESTINATION bin)
