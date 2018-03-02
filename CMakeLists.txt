cmake_minimum_required(VERSION 3.9)
project(cpp_nanotekspice)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_nanotekspice
        components/include/4001.hpp
        components/include/4008.hpp
        components/include/4011.hpp
        components/include/4013.hpp
        components/include/4017.hpp
        components/include/4030.hpp
        components/include/4069.hpp
        components/include/4071.hpp
        components/include/4081.hpp
        components/include/4094.hpp
        components/include/4514.hpp
        components/include/Input.hpp
        components/include/Output.hpp
        components/srcs/4001.cpp
        components/srcs/4008.cpp
        components/srcs/4011.cpp
        components/srcs/4013.cpp
        components/srcs/4017.cpp
        components/srcs/4030.cpp
        components/srcs/4069.cpp
        components/srcs/4071.cpp
        components/srcs/4081.cpp
        components/srcs/4094.cpp
        components/srcs/4514.cpp
        components/srcs/Input.cpp
        components/srcs/Output.cpp
        include/AComponent.hpp
        include/ErrorManage.hpp
        include/gate.hpp
        include/IComponent.hpp
        include/Parser.hpp
        include/Pin.hpp
        include/prompt.hpp
        srcs/AComponent.cpp
        srcs/ErrorManage.cpp
        srcs/gate.cpp
        srcs/main.cpp
        srcs/Parser.cpp
        srcs/prompt.cpp
        srcs/t_main.cpp
        srcs/test.cpp
        Prompt.hpp)
