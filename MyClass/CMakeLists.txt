project(embind_test)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE *.cpp)

add_executable(${PROJECT_NAME} ${SOURCE})


if (EMSCRIPTEN)
    set(OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/${PROJECT_NAME}")
    set(TYPEDEF_FILE index.d.ts)
    add_custom_target(
            generate_types
            COMMAND ${CMAKE_C_COMPILER} -lembind ${SOURCE} -sEXPORTED_FUNCTIONS=_free,_main --embind-emit-tsd ${TYPEDEF_FILE}

            # move the interface.d.ts to the build folder
            COMMAND mv ${CMAKE_CURRENT_BINARY_DIR}/${TYPEDEF_FILE} ${OUTPUT_PATH}/${TYPEDEF_FILE})
    set_target_properties(${PROJECT_NAME} PROPERTIES
            SUFFIX ".js"
            LINK_FLAGS "-lembind"
            RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    )

    add_dependencies(${PROJECT_NAME} generate_types)
endif()
