project(embind_test)

set(CMAKE_CXX_STANDARD 17)

# define source files
file(GLOB_RECURSE SOURCE *.cpp)

# add source to main project
add_executable(${PROJECT_NAME} ${SOURCE})

# Emscripten compile targets
if (EMSCRIPTEN)
    set(OUTPUT_PATH "${CMAKE_SOURCE_DIR}/lib/${PROJECT_NAME}")
    set(TYPEDEF_FILE ${PROJECT_NAME}.d.ts)

    # Set target properties for the main project
    set_target_properties(${PROJECT_NAME} PROPERTIES
            SUFFIX ".js"
            LINK_FLAGS "-lembind"
            RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_PATH}
    )

    # Generate the typescript definitions from the source
    add_custom_command(
            TARGET ${PROJECT_NAME}
            PRE_BUILD
            DEPENDS ${OUTPUT_PATH}/${PROJECT_NAME}.js

            # generate the typescript definitions
            COMMAND ${CMAKE_C_COMPILER} ARGS
                -lembind
                ${SOURCE}

                # for some reason, compiler complains _free is undefined -
                # it may be a bug in --embind-emit-tsd?
                -sEXPORTED_FUNCTIONS=_free,_main
                --embind-emit-tsd ${TYPEDEF_FILE}

            # copy the interface.d.ts to the build folder
            COMMAND ${CMAKE_COMMAND} ARGS
                -E copy ${CMAKE_CURRENT_BINARY_DIR}/${TYPEDEF_FILE} ${OUTPUT_PATH}

            # append default module export JS syntax at end of the generated d.ts file
            # this may not be cross-platform - only tested on MacOS
            COMMAND echo ARGS
            'declare const Module: MainModule\; export default Module\;'
            >> ${OUTPUT_PATH}/${TYPEDEF_FILE}


    )

endif()
