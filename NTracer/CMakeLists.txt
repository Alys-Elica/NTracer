cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME NTracer)

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME}
  NT_3DObjects/nt3dobject.h
  NT_3DObjects/nt3dobjectplane.h
  NT_3DObjects/nt3dobjectsphere.h
  NT_Base/ntcamera.h
  NT_Base/ntcolor.h
  NT_Base/ntintersection.h
  NT_Base/ntmaterial.h
  NT_Base/ntray.h
  NT_Base/ntrenderer.h
  NT_Base/ntscene.h
  NT_Light/ntlight.h
  NT_Light/ntlightomni.h
  
  NT_3DObjects/nt3dobject.cpp
  NT_3DObjects/nt3dobjectplane.cpp
  NT_3DObjects/nt3dobjectsphere.cpp
  NT_Base/ntcamera.cpp
  NT_Base/ntcolor.cpp
  NT_Base/ntintersection.cpp
  NT_Base/ntmaterial.cpp
  NT_Base/ntray.cpp
  NT_Base/ntrenderer.cpp
  NT_Base/ntscene.cpp
  NT_Light/ntlight.cpp
  NT_Light/ntlightomni.cpp
  main.cpp
)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC NCore)

# SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main)
