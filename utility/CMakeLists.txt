set(SOURCE_FILES
	"LaunchWrapperSink.cpp"
	"targetver.h"
)

add_executable(LaunchWrapperSink ${SOURCE_FILES})
cz_setCommonBinaryProperties(LaunchWrapper "/")

