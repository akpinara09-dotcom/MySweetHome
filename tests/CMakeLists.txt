# Test executable
add_executable(unit_tests test_main.cpp)

# Link against the core library
target_link_libraries(unit_tests PRIVATE msh_lib)

# Register tests
add_test(NAME CoreTests COMMAND unit_tests)