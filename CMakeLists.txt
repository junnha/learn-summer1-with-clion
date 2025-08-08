cmake_minimum_required(VERSION 3.31)
project(Summerlearn1withClion)

set(CMAKE_CXX_STANDARD 26)

# 현재 폴더에 있는 모든 .cpp 파일을 찾음
file(GLOB SOURCES "*.cpp")

# 각각의 .cpp 파일마다 실행 파일 생성
foreach (source_file ${SOURCES})
    # 파일명에서 확장자 제거 (ex: 4179.cpp → 4179)
    get_filename_component(exec_name ${source_file} NAME_WE)
    add_executable(${exec_name} ${source_file}
            1920.cpp)
endforeach ()
add_executable(Out 1012.cpp)
