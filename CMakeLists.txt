cmake_minimum_required(VERSION 3.13)
project(implementation)

set(CMAKE_CXX_STANDARD 17)

# Przyjmij, że główny katalog z plikami frameworku GTF znajduje się
# dwa katalogi wyżej względem katalogu projektu.
set(GTEST_ROOT ../googletest-master)

include_directories(
        include

)

set(SOURCE_FILES
        src/tsp_setup.cpp
        src/TSP.cpp
        )

set(SOURCES_FILES_TESTS
        tests/tests.cpp)

set(EXEC_TEST ${PROJECT_ID}__test)

##dodac test/main_gtest
add_executable(tsp ${SOURCE_FILES} main.cpp )
add_executable(${EXEC_TEST} ${SOURCE_FILES} ${SOURCES_FILES_TESTS})



#Dodaj katalogi z plikami nagłówkowymi GTF.
target_include_directories(${EXEC_TEST} PUBLIC
        ${GTEST_ROOT}/googlemock/include
        ${GTEST_ROOT}/googletest/include
        )

add_subdirectory(${GTEST_ROOT} googletest-master)

# Dołącz bibliotekę Google Mock.
target_link_libraries(${EXEC_TEST} gmock gtest)


