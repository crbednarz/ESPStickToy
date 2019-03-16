cmake_minimum_required(VERSION 3.5)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

include("common/utilities.cmake")
set(EXTRA_COMPONENT_DIRS "${EXTRA_COMPONENT_DIRS} common/components")

project(ESPStickToy)
