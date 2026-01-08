cmake_minimum_required(VERSION 4.0)
project(supermarket)

set(CMAKE_CXX_STANDARD 20)

add_executable(supermarket main.cpp
        product.cpp
        product.h
        FoodProduct.cpp
        FoodProduct.h
        ElectronicProduct.cpp
        ElectronicProduct.h
        HouseholdProduct.cpp
        HouseholdProduct.h
        Supermarket.cpp
        Supermarket.h
        Cart.cpp
        Cart.h
        Customer.cpp
        Customer.h
        Order.cpp
        Order.h
        OrderItem.cpp
        OrderItem.h)
