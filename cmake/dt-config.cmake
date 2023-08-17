include(CMakeFindDependencyMacro)

set(DT_INCLUDE_DIRS "${CMAKE_INSTALL_PREFIX}/include/")
set(DT_LIBRARIES "/usr/local/lib/libdt.a")

set(DT_FOUND TRUE)

# Provide version information
#include("${CMAKE_CURRENT_LIST_DIR}/dt-version.cmake")

# Define imported target
add_library(dt::dt INTERFACE IMPORTED)
set_target_properties(dt::dt PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${DT_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${DT_LIBRARIES}"
)

# Notify dependent projects that this package has been found
#include(CMakePackageConfigHelpers)
#configure_package_config_file(
#        "${CMAKE_CURRENT_LIST_DIR}/dt-config.cmake.in"
#        "${CMAKE_CURRENT_BINARY_DIR}/dt-config.cmake"
#        INSTALL_DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/dt"
#)
#write_basic_package_version_file(
#        "${CMAKE_CURRENT_BINARY_DIR}/dt-version.cmake"
#        VERSION ${DT_VERSION}
#        COMPATIBILITY AnyNewerVersion
#)

# Install the generated files
install(
        FILES
        "${CMAKE_CURRENT_BINARY_DIR}/dt-config.cmake"
        DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/dt"
)

