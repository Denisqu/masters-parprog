file(GLOB_RECURSE SHARED_HEADERS "/shared/*hpp")
set(SHARED_HEADERS_PATH "/shared" CACHE PATH "Path to shared definitions")

add_subdirectory(singlethreaded_nonvectorized)