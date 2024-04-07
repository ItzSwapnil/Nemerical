cmake_minimum_required(VERSION 3.28)
project(Numerical C)

set(CMAKE_C_STANDARD 23)

add_executable(Numerical main.c)

add_executable(sum_of_2_matrix sum_of_2_matrix.c)
add_executable(sub_of_2_matrix sub_of_2_matrix.c)

add_executable(Bisection_method Bisection_method.c)
add_executable(Newtons_Forward_Interpolation Newtons_Forward_Interpolation.c)
add_executable(Newtons_Backward_Interpolation Newtons_Backward_Interpolation.c)