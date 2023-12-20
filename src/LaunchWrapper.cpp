#include "targetver.h"
#include <crazygaze/muc/ChildProcessLauncher.h>
#include <crazygaze/muc/IniFile.h>
#include <crazygaze/muc/Filesystem.h>
#include <crazygaze/muc/StringUtils.h>
#include <crazygaze/muc/UTF8String.h>
#include <conio.h>

int main(int argc, char* argv[])
{
	cz::Filesystem filesystem;

	filesystem.setCWDToDefault();

	cz::IniFile cfg;
	if (!cfg.open("LaunchWrapper.ini"))
	{
		printf("Could not open wrapper config file 'LaunchWrapper.ini'\n");
		while (!kbhit()) {}
		return EXIT_FAILURE;
	}

	std::string process = cz::trim(std::string(cfg.getValue("", "process", "")));
	std::string extra_params = cz::trim(std::string(cfg.getValue("", "extra_params", "")));
	std::string extra_params_before = cz::trim(std::string(cfg.getValue("", "extra_params_before", "")));
	bool pause_on_finished = cfg.getValue("", "pause_on_finished", false);
	if (process.empty())
	{
		printf("`process` not specified or empty in config file 'LaunchWrapper.ini'\n");
		while (!kbhit()) {}
		return EXIT_FAILURE;
	}


	cz::UTF8String workingDirectory = cz::Filename(process.c_str()).getDirectory().c_str();
	printf("LauncWrapper: Setting working directory to: %s\n", workingDirectory.c_str());
	cz::Filesystem::getSingleton().setCWD(workingDirectory);

	cz::ChildProcessLauncher launcher;

	std::string args = extra_params_before + " ";
	for (int i = 1; i < argc; i++)
	{
		args += std::string(" ") + argv[i];
	}
	args += std::string(" ") + extra_params;
	int ret = EXIT_SUCCESS;


	if (process != "none")
	{
		ret = launcher.launch(process, args, true, [](bool fromLaunchWrapper, const std::string& str)
			{
				if (fromLaunchWrapper)
				{
					printf("LaunchWrapper: %s", str.c_str());
				}
				else
				{
					printf("%s", str.c_str());
				}
			});
	}

	if (pause_on_finished)
	{
		while(!kbhit());
	}

	return ret;

}