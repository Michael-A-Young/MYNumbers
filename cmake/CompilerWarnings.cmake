include_guard(GLOBAL)

function(MY_configure_warnings TARGET)

	if(NOT TARGET ${TARGET})
		message(
			FATAL_ERROR
			"set_project_warnings: '${TARGET}' is not a target."
		)
	endif()

	if(MSVC)

		target_compile_options(
			${TARGET}
			PRIVATE
			/W4
		)

		if(MY_WARNINGS_AS_ERRORS)
			target_compile_options(
				${TARGET}
				PRIVATE
				/WX
			)
		endif()

	elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")

		target_compile_options(
			${TARGET}
			PRIVATE
			-Wall
			-Wextra
			-Wpedantic
		)

		if(MY_WARNINGS_AS_ERRORS)
			target_compile_options(
				${TARGET}
				PRIVATE
				-Werror
			)
		endif()

	else()
		message(
			FATAL_ERROR
			"set_project_warnings: Unknown compiler '${CMAKE_CXX_COMPILER_ID}'."
		)
	endif()

endfunction()
