cmake_minimum_required(VERSION 3.10)

project(image_feature_tester)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(include)

add_executable(${PROJECT_NAME}
    src/image_feature_tester_main.cpp
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets
    ${OpenCV_LIBS}
)

