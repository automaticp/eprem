file(GLOB local_sources CONFIGURE_DEPENDS ./*.c)
add_executable(eprem ${local_sources})
target_include_directories(eprem PRIVATE ./)
target_compile_features(eprem PRIVATE c_std_99)

find_package(MPI    REQUIRED)
find_package(HDF5   REQUIRED)
find_package(Config REQUIRED)
find_package(NetCDF REQUIRED)

target_link_libraries(eprem PRIVATE MPI::MPI_C HDF5::HDF5 Config::Config NetCDF::NetCDF)
