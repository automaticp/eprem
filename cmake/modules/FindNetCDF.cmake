# Exports NetCDF::NetCDF target.

include(_FindHelpers)

find_simple_external_library(
    NetCDF
    LIBRARY_NAMES netcdf libnetcdf
    HEADER_NAMES netcdf.h
)
