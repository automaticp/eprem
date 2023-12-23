# Exports Config::Config target.

include(_FindHelpers)

find_simple_external_library(
    Config
    LIBRARY_NAMES config libconfig
    HEADER_NAMES libconfig.h
)
