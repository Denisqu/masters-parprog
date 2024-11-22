file(GLOB_RECURSE SHARED_HEADERS_ "./shared/*.hpp")
set(SHARED_HEADERS ${SHARED_HEADERS_} CACHE STRING "List of shared headers")
#set(SHARED_HEADERS_PATH "./shared" CACHE PATH "Path to shared definitions")

add_subdirectory(shared)
add_subdirectory(singlethreaded_nonvectorized)
