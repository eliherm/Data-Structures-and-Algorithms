cmake_minimum_required(VERSION 3.14)
project(elec278_1)

set(CMAKE_C_STANDARD 11)

add_executable(HelloWorld step2/HelloWorld.c)
add_executable(MatrixMult step3/MatrixMult.c)
add_executable(myString step4/main.c step4/myString.c)
add_executable(llist step5/main.c step5/llist1.c)