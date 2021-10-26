cmake_minimum_required(VERSION 3.20)
project(CPrimerPlus C)

set(CMAKE_C_STANDARD 11)

# 课程代码
add_executable(inform assets/codes/Ch01/inform.c)
add_executable(listing1 assets/codes/Ch01/listing1.c)
add_executable(listing2 assets/codes/Ch01/listing2.c)

# 编程练习
add_executable(ex2-01 exercises/ch02/ex01.c)
add_executable(ex2-03 exercises/ch02/ex03.c)
add_executable(ex2-04 exercises/ch02/ex04.c)
add_executable(ex2-05 exercises/ch02/ex05.c)
add_executable(ex2-06 exercises/ch02/ex06.c)
add_executable(ex2-07 exercises/ch02/ex07.c)
add_executable(ex2-08 exercises/ch02/ex08.c)