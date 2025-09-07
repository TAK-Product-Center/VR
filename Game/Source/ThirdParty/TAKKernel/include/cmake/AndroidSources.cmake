# Support script for mapengine/CMakeLists.txt that sets sources, definitions, includes, link libraries, link directories,
# and compiler options that are specific to Android targets.

set(takengine_ANDROID_DEFS
    RTTI_ENABLED
    -DTE_GLES_VERSION=3
    SQLITE_HAS_CODEC
	BOOST_NO_AUTO_PTR
	TINYGLTF_ENABLE_DRACO
	SPDLOG_COMPILED_LIB
    LIBASYNC_STATIC
	GLM_FORCE_XYZW_ONLY
	GLM_FORCE_EXPLICIT_CTOR
	GLM_FORCE_SIZE_T_LENGTH
)



set(takengine_ANDROID_INCS
	${draco_INCLUDE_DIRS}
	${cesium-native_INCLUDE_DIRS}
)

set(takengine_ANDROID_LDIRS
	${cesium-native_LIB_DIRS}
    ${ttp-dist_LIB_DIRS}
	${libLAS_LIB_DIRS}
	${draco_LIB_DIRS}
)

set(takengine_ANDROID_CESIUM_NATIVE_LIBS
	# cesium native
	#Cesium3DTiles
	Cesium3DTilesContent
	Cesium3DTilesReader
	Cesium3DTilesSelection
	#Cesium3DTilesWriter
	CesiumAsync
	CesiumGeometry
	CesiumGeospatial
	CesiumGltf
	CesiumGltfContent
	CesiumGltfReader
	#CesiumGltfWriter
	#CesiumIonClient
	CesiumJsonReader
	#CesiumJsonWriter
	CesiumQuantizedMeshTerrain
	CesiumRasterOverlays
	CesiumUtility
	#absl_bad_any_cast_impl
	#absl_bad_optional_access
	#absl_bad_variant_access
	absl_base
	absl_city
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
	absl_debugging_internal
	#absl_demangle_internal
	#absl_die_if_null
	absl_examine_stack
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
	#absl_graphcycles_internal
	absl_hash
	#absl_hashtablez_sampler
	absl_int128
	absl_kernel_timeout_internal
	#absl_leak_check
	#absl_log_entry
	#absl_log_flags
	absl_log_globals
	#absl_log_initialize
	absl_log_internal_check_op
	absl_log_internal_conditions
	absl_log_internal_fnmatch
	absl_log_internal_format
	absl_log_internal_globals
	absl_log_internal_log_sink_set
	absl_log_internal_message
	absl_log_internal_nullguard
	absl_log_internal_proto
	#absl_log_severity
	absl_log_sink
	absl_low_level_hash
	absl_malloc_internal
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
	absl_raw_logging_internal
	#absl_scoped_set_env
	absl_spinlock_wait
	absl_stacktrace
	#absl_status
	#absl_statusor
	absl_str_format_internal
	absl_strerror
	absl_string_view
	absl_strings
	#absl_strings_internal
	absl_symbolize
	absl_synchronization
	absl_throw_delegate
	absl_time
	absl_time_zone
	#absl_vlog_config_internal
	async++
	fmt
	ktx
	libmodpbase64
	meshoptimizer
	s2
	#sharpyuv
	spdlog
	#tinyxml2
	turbojpeg
	uriparser
	webp
	webpdecoder
	webpdemux
	#webpmux
	#z-ng
	zstd
)

set(takengine_ANDROID_LIBS
	${takengine_ANDROID_CESIUM_NATIVE_LIBS}

    # TTP
    spatialite
    gdal
    mdb
    assimp

    # System
    log
    GLESv3

    las
    las_c
	draco

	# System
	log
	GLESv3
)

set(takengine_ANDROID_OPTS
    $<$<NOT:$<BOOL:${MSVC}>>:-O3>
)
