cmake_minimum_required(VERSION 4.0)
project(supermarket)

set(CMAKE_CXX_STANDARD 20)

add_executable(supermarket main.cpp
        Order.cpp
        Customer.cpp
        ElectronicProduct.cpp
        FoodProduct.cpp
        HouseholdProduct.cpp
        OrderItem.cpp
        product.cpp
        Supermarket.cpp
        Cart.cpp)
