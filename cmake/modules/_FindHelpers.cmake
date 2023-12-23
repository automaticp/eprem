function(_add_imported_library name library_path include_dirs)

    set(tgt "${name}::${name}")

    add_library(${tgt} UNKNOWN IMPORTED)
    set_target_properties(${tgt} PROPERTIES IMPORTED_LOCATION ${library_path})
    target_include_directories(${tgt} INTERFACE ${include_dirs})

    # set(${name}_FOUND TRUE CACHE INTERNAL "" FORCE)
    set(${name}_LIBRARY_PATH ${library_path} CACHE STRING "" FORCE)
    set(${name}_INCLUDE_DIRS ${include_dirs} CACHE STRING "" FORCE)

    mark_as_advanced(FORCE ${name}_LIBRARY_PATH)
    mark_as_advanced(FORCE ${name}_INCLUDE_DIRS)

endfunction()


include(FindPackageHandleStandardArgs)


function(find_simple_external_library name #[[ LIBRARY_NAMES ... HEADER_NAMES ... #]])

    # If the variables are aleady specified by the user
    # or cached from the previous configuration run, use them.
    if (${name}_LIBRARY_PATH AND ${name}_INCLUDE_DIRS)

        _add_imported_library(
            ${name}
            ${${name}_LIBRARY_PATH}
            ${${name}_INCLUDE_DIRS}
        )

    else()

        cmake_parse_arguments(ARG "" "" "LIBRARY_NAMES;HEADER_NAMES" ${ARGN})

        find_library(${name}_LIBRARY_PATH NAMES ${ARG_LIBRARY_NAMES})
        find_path(   ${name}_INCLUDE_DIRS NAMES ${ARG_HEADER_NAMES} )

        find_package_handle_standard_args(
            ${name}
            DEFAULT_MSG
            ${name}_LIBRARY_PATH
            ${name}_INCLUDE_DIRS
        )

        if (${name}_FOUND)
            _add_imported_library(
                ${name}
                ${${name}_LIBRARY_PATH}
                ${${name}_INCLUDE_DIRS}
            )
        endif()
    endif()

endfunction()
