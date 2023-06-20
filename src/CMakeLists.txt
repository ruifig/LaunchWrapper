set(SOURCE_FILES
	"LaunchWrapper.cpp"
	"targetver.h"
)

add_executable(LaunchWrapper ${SOURCE_FILES})
target_link_libraries(LaunchWrapper czmuc)
set_property(TARGET czmuc PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
set_property(TARGET LaunchWrapper PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
cz_setCommonBinaryProperties(LaunchWrapper "/")

