set(SOURCE_FILES
	"LaunchWrapperSink.cpp"
	"targetver.h"
)

add_executable(LaunchWrapperSink ${SOURCE_FILES})
set_property(TARGET LaunchWrapperSink PROPERTY
  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
cz_setCommonBinaryProperties(LaunchWrapper "/")

