add_library(pepequeue
    STATIC
    netfilter_queue.cpp
)

target_include_directories(pepequeue PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(pepequeue
    PUBLIC
    Threads::Threads
    tins
)

install(TARGETS pepequeue
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
)
