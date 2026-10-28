cmake_minimum_required(VERSION 3.15)
project(pyc_compiler CXX)

# Устанавливаем стандарт C++ (например, C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Создаем статическую библиотеку рантайма
add_library(pyc_runtime STATIC
    runtime/src/type.cpp
    runtime/src/exception.cpp
    runtime/src/builtins.cpp
    runtime/src/types/int.cpp
    runtime/src/types/str.cpp
    runtime/src/types/list.cpp
    runtime/src/types/dict.cpp
)

# Указываем, где компилятору искать заголовочные файлы рантайма
# PUBLIC означает, что те, кто линкует pyc_runtime, тоже получат этот путь к заголовкам
target_include_directories(pyc_runtime PUBLIC
    runtime/include
)

# 2. Создаем главный исполняемый файл компилятора (pyc)
add_executable(pyc
    src/main.cpp
    # Если у компилятора появятся свои .cpp файлы в src/, их нужно добавить сюда:
    # src/lexer.cpp
    # src/parser.cpp
)

# 3. Связываем (линкуем) исполняемый файл pyc с библиотекой рантайма
target_link_libraries(pyc PRIVATE pyc_runtime)