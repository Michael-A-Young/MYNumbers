cmake_minimum_required(VERSION 3.25)

project(
	MYTemplate
	VERSION 0.1.0
	DESCRIPTION "Project template"
	LANGUAGES CXX
)

# ---------------------------------------------------------------------------
# Options
# ---------------------------------------------------------------------------

option(
	MY_WARNINGS_AS_ERRORS
	"Treat compiler warnings as errors"
	ON
)

option(
	MY_ENABLE_CLANG_TIDY
	"Run clang-tidy during compilation"
	OFF
)

option(
	MY_ENABLE_ASAN
	"Enable AddressSanitizer"
	OFF
)

option(
	MY_ENABLE_UBSAN
	"Enable UndefinedBehaviorSanitizer"
	OFF
)

option(
	MY_ENABLE_TSAN
	"Enable ThreadSanitizer"
	OFF
)

# ---------------------------------------------------------------------------
# CMake modules
# ---------------------------------------------------------------------------

list(
	APPEND CMAKE_MODULE_PATH
	"${CMAKE_CURRENT_SOURCE_DIR}/cmake"
)

include(CompilerWarnings)
include(Sanitisers)
include(StaticAnalysis)

# ---------------------------------------------------------------------------
# Source
# ---------------------------------------------------------------------------

add_executable(
	MYTemplate
	src/main.cpp
)

target_include_directories(
	MYTemplate
	PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---------------------------------------------------------------------------
# Project configuration
# ---------------------------------------------------------------------------

target_compile_features(MYTemplate PRIVATE cxx_std_23)

set_target_properties(
	MYTemplate
	PROPERTIES
    CXX_EXTENSIONS OFF
)

# ---------------------------------------------------------------------------
# Warnings / sanitizers / static analysis
# ---------------------------------------------------------------------------

MY_configure_warnings(MYTemplate)
MY_configure_sanitisers(MYTemplate)
MY_configure_static_analysis(MYTemplate)
