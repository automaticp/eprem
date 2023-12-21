file(GLOB local_sources CONFIGURE_DEPENDS ./*.c)
add_executable(eprem ${local_sources})
target_include_directories(eprem PRIVATE ./)
target_compile_features(eprem PRIVATE c_std_99)


find_package(MPI REQUIRED)
add_library(mpi::mpi IMPORTED INTERFACE)
target_link_libraries(mpi::mpi INTERFACE ${MPI_mpich_LIBRARY})
target_include_directories(mpi::mpi
    INTERFACE
        ${MPI_C_COMPILER_INCLUDE_DIRS}
        ${MPI_C_ADDITIONAL_INCLUDE_DIRS}
        ${MPI_C_INCLUDE_DIRS}
        ${MPI_C_HEADER_DIR}
)
target_compile_definitions(mpi::mpi INTERFACE ${MPI_C_COMPILE_DEFINITIONS})
target_compile_options(mpi::mpi INTERFACE ${MPI_C_COMPILE_OPTIONS})
target_link_options(mpi::mpi INTERFACE ${MPI_C_LINK_FLAGS})


find_package(HDF5 REQUIRED)


# No Find/Config file for these, but they spit their headers into system include dir
# find_package(libnetcdf REQUIRED)
# find_package(libconfig REQUIRED)


target_link_libraries(eprem PRIVATE mpi::mpi hdf5::hdf5)
target_link_libraries(eprem PRIVATE "m" "netcdf" "config")
