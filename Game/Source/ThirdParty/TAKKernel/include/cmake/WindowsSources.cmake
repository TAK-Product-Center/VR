# Support script for mapengine/CMakeLists.txt that sets sources, definitions, includes, link libraries, link directories,
# and compiler options that are specific to Windows targets.

set(takengine_WINDOWS_DEFS
    use_namespace
    WIN32_LEAN_AND_MEAN
    WIN32
    EMULATE_GL_LINES
    _USE_MATH_DEFINES
    NOMINMAX
    ENGINE_EXPORTS
    SQLITE_HAS_CODEC
    ZLIB_DLL
    ZLIB_WINAPI
    $<IF:$<CONFIG:Debug>,_DEBUG,_NDEBUG>
    _SCL_SECURE_NO_WARNINGS
    _CRT_SECURE_NO_WARNINGS
    $<$<BOOL:${MSVC}>:MSVC>
	BOOST_NO_AUTO_PTR
    TINYGLTF_ENABLE_DRACO
	SPDLOG_COMPILED_LIB
    LIBASYNC_STATIC
)

set(takengine_WINDOWS_INCS
    ${SRC_DIR}/../cpp-cli/vscompat
	${draco_INCLUDE_DIRS}
	${cesium-native_INCLUDE_DIRS}
)

set(takengine_WINDOWS_CESIUM_NATIVE_LIBS
	# cesium native
	#debug Cesium3DTilesd
	#optimized Cesium3DTiles
	debug debug/Cesium3DTilesContent
	optimized Cesium3DTilesContent
	debug debug/Cesium3DTilesReader
	optimized Cesium3DTilesReader
	debug debug/Cesium3DTilesSelection
	optimized Cesium3DTilesSelection
	#Cesium3DTilesWriter
	debug debug/CesiumAsync
	optimized CesiumAsync
	debug debug/CesiumGeometry
	optimized CesiumGeometry
	debug debug/CesiumGeospatial
	optimized CesiumGeospatial
	debug debug/CesiumGltf
	optimized CesiumGltf
	debug debug/CesiumGltfContent
	optimized CesiumGltfContent
	debug debug/CesiumGltfReader
	optimized CesiumGltfReader
	#CesiumGltfWriter
	#CesiumIonClient
	debug debug/CesiumJsonReader
	optimized CesiumJsonReader
	#CesiumJsonWriter
	debug debug/CesiumQuantizedMeshTerrain
	optimized CesiumQuantizedMeshTerrain
	debug debug/CesiumRasterOverlays
	optimized CesiumRasterOverlays
	debug debug/CesiumUtility
	optimized CesiumUtility
	#absl_bad_any_cast_impl
	#absl_bad_optional_access
	#absl_bad_variant_access
	debug debug/absl_base
	optimized absl_base
	debug debug/absl_city
	optimized absl_city
	#absl_civil_time
	#absl_cord
	#absl_cord_internal
	#absl_cordz_functions
	#absl_cordz_handle
	#absl_cordz_info
	#absl_cordz_sample_token
	#absl_crc32c
	#absl_crc_cord_state
	#absl_crc_cpu_detect
	#absl_crc_internal
	debug debug/absl_debugging_internal
	optimized absl_debugging_internal
	#absl_demangle_internal
	#absl_die_if_null
	debug debug/absl_examine_stack
	optimized absl_examine_stack
	#absl_exponential_biased
	#absl_failure_signal_handler
	#absl_flags_commandlineflag
	#absl_flags_commandlineflag_internal
	#absl_flags_config
	#absl_flags_internal
	#absl_flags_marshalling
	#absl_flags_parse
	#absl_flags_private_handle_accessor
	#absl_flags_program_name
	#absl_flags_reflection
	#absl_flags_usage
	#absl_flags_usage_internal
	debug debug/absl_graphcycles_internal
	optimized absl_graphcycles_internal
	debug debug/absl_hash
	optimized absl_hash
	#absl_hashtablez_sampler
	debug debug/absl_int128
	optimized absl_int128
	debug debug/absl_kernel_timeout_internal
	optimized absl_kernel_timeout_internal
	#absl_leak_check
	#absl_log_entry
	#absl_log_flags
	debug debug/absl_log_globals
	optimized absl_log_globals
	#absl_log_initialize
	debug debug/absl_log_internal_check_op
	optimized absl_log_internal_check_op
	debug debug/absl_log_internal_conditions
	optimized absl_log_internal_conditions
	debug debug/absl_log_internal_fnmatch
	optimized absl_log_internal_fnmatch
	debug debug/absl_log_internal_format
	optimized absl_log_internal_format
	debug debug/absl_log_internal_globals
	optimized absl_log_internal_globals
	debug debug/absl_log_internal_log_sink_set
	optimized absl_log_internal_log_sink_set
	debug debug/absl_log_internal_message
	optimized absl_log_internal_message
	debug debug/absl_log_internal_nullguard
	optimized absl_log_internal_nullguard
	debug debug/absl_log_internal_proto
	optimized absl_log_internal_proto
	#absl_log_severity
	debug debug/absl_log_sink
	optimized absl_log_sink
	debug debug/absl_low_level_hash
	optimized absl_low_level_hash
	debug debug/absl_malloc_internal
	optimized absl_malloc_internal
	#absl_periodic_sampler
	#absl_random_distributions
	#absl_random_internal_distribution_test_util
	#absl_random_internal_platform
	#absl_random_internal_pool_urbg
	#absl_random_internal_randen
	#absl_random_internal_randen_hwaes
	#absl_random_internal_randen_hwaes_impl
	#absl_random_internal_randen_slow
	#absl_random_internal_seed_material
	#absl_random_seed_gen_exception
	#absl_random_seed_sequences
	#absl_raw_hash_set
	debug debug/absl_raw_logging_internal
	optimized absl_raw_logging_internal
	#absl_scoped_set_env
	debug debug/absl_spinlock_wait
	optimized absl_spinlock_wait
	debug debug/absl_stacktrace
	optimized absl_stacktrace
	#absl_status
	#absl_statusor
	debug debug/absl_str_format_internal
	optimized absl_str_format_internal
	debug debug/absl_strerror
	optimized absl_strerror
	debug debug/absl_string_view
	optimized absl_string_view
	debug debug/absl_strings
	optimized absl_strings
	#absl_strings_internal
	debug debug/absl_symbolize
	optimized absl_symbolize
	debug debug/absl_synchronization
	optimized absl_synchronization
	debug debug/absl_throw_delegate
	optimized absl_throw_delegate
	debug debug/absl_time
	optimized absl_time
	debug debug/absl_time_zone
	optimized absl_time_zone
	#absl_vlog_config_internal
	#async++
	debug debug/async++
	optimized async++
	#debug debug/draco
	#optimized draco
	debug debug/fmtd
	optimized fmt
	#glm
	#jpeg
	debug debug/ktx
	optimized ktx
	#libcrypto
	debug debug/libmodpbase64
	optimized libmodpbase64
	#libsharpyuv
	#libssl	12.2 MiB
	debug debug/libwebp
	optimized libwebp
	debug debug/libwebpdecoder
	optimized libwebpdecoder
	debug debug/libwebpdemux
	optimized libwebpdemux
	#libwebpmux
	debug debug/meshoptimizer
	optimized meshoptimizer
	debug debug/s2
	optimized s2
	debug debug/spdlogd
	optimized spdlog
	#tinyxml2
	debug debug/turbojpeg
	optimized turbojpeg
	debug debug/uriparser
	optimized uriparser
	#z-ng
	debug debug/zstd
	optimized zstd
)

set(takengine_WINDOWS_LIBS
    # GLES
    lib/GLESv2

    # Configuration dependent TTP
    debug debuglib/libkmlbase
    optimized lib/libkmlbase
    debug debuglib/libkmlconvenience
    optimized lib/libkmlconvenience
    debug debuglib/libkmldom
    optimized lib/libkmldom
    debug debuglib/libkmlengine
    optimized lib/libkmlengine
    debug debuglib/libkmlregionator
    optimized lib/libkmlregionator
    debug debuglib/libkmlxsd
    optimized lib/libkmlxsd

    # General TTP
    lib/sqlite3_i
    lib/spatialite_i
    lib/libxml2
    lib/geos_c_i
    lib/proj_i
    lib/minizip_static
    lib/libexpat
    lib/uriparser
    lib/zlibwapi
    lib/gdal_i
    lib/mdb
    lib/ogdi
    lib/assimp
    lib/libcurl
    lib/libssl
    lib/libcrypto

    # XXX--liblas (anomaly on liblas windows build CMake path for release is in "Debug" folder)
    Debug/liblas
    Debug/liblas_c

    # System
    Dbghelp

    debug debug/draco
    optimized draco

	${takengine_WINDOWS_CESIUM_NATIVE_LIBS}
)

set(takengine_WINDOWS_LDIRS
    #XXX-- package_info provides only the one lib path. Ideally it would be both and release and debug libraries would have unique names
    ${ttp-dist_LIB_DIRS}/..
    ${GLES-stub_LIB_DIRS}/..
    ${libLAS_LIB_DIRS}
    ${draco_LIB_DIRS}/..
	${cesium-native_LIB_DIRS}
)

set(takengine_WINDOWS_OPTS
    # Set optimization level based on configuration.
    $<IF:$<CONFIG:Debug>,/Od,/O2>

    # Create PDBs for Debug and Release
    $<$<CONFIG:Release>:/Zi>

    # Treat warnings 4456, 4458, and (if generating Debug configuration) 4706 as errors.
    /we4456
    /we4458
    $<$<CONFIG:Debug>:/we4706>

    # Disable warnings 4091, 4100, 4127, 4251, 4275, 4290, and (if generating Release configuration) 4800.
    /wd4091
    /wd4100
    /wd4127
    /wd4251
    /wd4275
    /wd4290
    $<$<CONFIG:Release>:/wd4800>

    # Set Warning Level to 3 and Treat warnings as Errors
    /W3
    /WX
)

