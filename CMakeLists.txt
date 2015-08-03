# CMake file for GameTheory.
cmake_minimum_required (VERSION 2.8.9)
project(game_theory)

# Setup the directories
set(PROJECT_DIR ~/peanut/)
set(SOURCE_DIR $PROJECT_DIR/source/)
set(BUILD_DIR $PROJECT_DIR/build/)

include_directories(${PROJECT_DIR})
add_executable(game_theory 
  main.c 
  player.h 
  player.c
  logger.h
  )
