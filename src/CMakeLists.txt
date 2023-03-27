set(SOURCE_FILES
	"LaunchWrapper.cpp"
	"targetver.h"
)

add_executable(LaunchWrapper ${SOURCE_FILES})
target_link_libraries(LaunchWrapper czmuc)
cz_setCommonBinaryProperties(LaunchWrapper "/")

