ADD_EXECUTABLE(utilsBenchmark src/utilsBenchmark.cpp) 
ADD_EXECUTABLE(example::utilsBenchmark ALIAS utilsBenchmark)

TARGET_LINK_LIBRARIES(utilsBenchmark PRIVATE benchmark::benchmark example::utils)
TARGET_INCLUDE_DIRECTORIES(utilsBenchmark PUBLIC include PRIVATE src)
TARGET_COMPILE_FEATURES(utilsBenchmark PUBLIC cxx_std_17)

INSTALL(TARGETS utilsBenchmark 
	RUNTIME DESTINATION bechmark)
