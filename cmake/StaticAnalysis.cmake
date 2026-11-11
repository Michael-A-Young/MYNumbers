include_guard(GLOBAL)

function(MY_configure_static_analysis TARGET)

	if(MY_ENABLE_CLANG_TIDY)

		find_program(
			CLANG_TIDY_EXECUTABLE
			NAMES
			clang-tidy
		)

		if(NOT CLANG_TIDY_EXECUTABLE)
			message(
				FATAL_ERROR
				"clang-tidy was not found."
			)
		endif()

		set_target_properties(
			${TARGET}
			PROPERTIES
			CXX_CLANG_TIDY
			"${CLANG_TIDY_EXECUTABLE}"
		)

	endif()

endfunction()
