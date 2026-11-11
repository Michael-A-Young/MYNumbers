cmake_minimum_required(VERSION 3.25)

project(
	MYNumbers
	VERSION 0.1.0
	DESCRIPTION "Number classification library"
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
# Library
# ---------------------------------------------------------------------------

add_library(
	MYNumbersLib
	STATIC
	src/Math.cpp
	src/BuiltInNumbers.cpp
	src/NumberCache.cpp
	src/NumberClassifier.cpp
	src/NumberCondition.cpp
	src/NumberQuery.cpp
	src/NumberRelationship.cpp
	src/NumberRelationshipRegistry.cpp
	src/NumberSequence.cpp
	src/NumberSequenceRegistry.cpp
	src/NumberType.cpp
	src/NumberTypeRegistry.cpp
)

target_include_directories(
	MYNumbersLib
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(MYNumbersLib PUBLIC cxx_std_23)

set_target_properties(
	MYNumbersLib
	PROPERTIES
	CXX_EXTENSIONS OFF
)

MY_configure_warnings(MYNumbersLib)
MY_configure_sanitisers(MYNumbersLib)
MY_configure_static_analysis(MYNumbersLib)

# ---------------------------------------------------------------------------
# Source
# ---------------------------------------------------------------------------

add_executable(
	MYNumbers
	src/main.cpp
)

target_link_libraries(
	MYNumbers
	PRIVATE
	MYNumbersLib
)

target_include_directories(
	MYNumbers
	PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ---------------------------------------------------------------------------
# Project configuration
# ---------------------------------------------------------------------------

target_compile_features(MYNumbers PRIVATE cxx_std_23)

set_target_properties(
	MYNumbers
	PROPERTIES
    CXX_EXTENSIONS OFF
)

# ---------------------------------------------------------------------------
# Warnings / sanitizers / static analysis
# ---------------------------------------------------------------------------

MY_configure_warnings(MYNumbers)
MY_configure_sanitisers(MYNumbers)
MY_configure_static_analysis(MYNumbers)
