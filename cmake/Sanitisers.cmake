include_guard(GLOBAL)

function(MY_configure_sanitisers TARGET)

	if(MY_ENABLE_TSAN AND MY_ENABLE_ASAN)
		message(
			FATAL_ERROR
			"ThreadSanitizer cannot be combined with AddressSanitizer."
		)
	endif()

	if(MY_ENABLE_ASAN)

		target_compile_options(
			${TARGET}
			PRIVATE
			-fsanitize=address
			-fno-omit-frame-pointer
		)

		target_link_options(
			${TARGET}
			PRIVATE
			-fsanitize=address
		)

	endif()

	if(MY_ENABLE_UBSAN)

		target_compile_options(
			${TARGET}
			PRIVATE
			-fsanitize=undefined
		)

		target_link_options(
			${TARGET}
			PRIVATE
			-fsanitize=undefined
		)

	endif()

	if(MY_ENABLE_TSAN)

		target_compile_options(
			${TARGET}
			PRIVATE
			-fsanitize=thread
		)

		target_link_options(
			${TARGET}
			PRIVATE
			-fsanitize=thread
		)

	endif()

endfunction()
