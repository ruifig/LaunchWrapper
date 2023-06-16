
# Very simple application launch wrapper.

What it does:

* Looks for a LaunchWrapper.ini in the same directory as the executable. The following is expected from the ini file:
	* **REQUIRED:** A `process=<PATH>` value, which is the full path to the process to launch. This process will be launched with all the parameters passed to LaunchWrapper
		* The hardcoded `none` (case sensitive) process name is accepted, and if specified  it will not spawn any process and will simply return an exit code 0 (Sucess)
	* **OPTIONAL:** A `params_extra` value, which specifies extra parameters to be passed to the launched process.


# How to build

* Clone
* Run `gen_vs_projects.bat`. It will download dependencies and generate VS projects
* Optionally, run `build_release.bat` after `gen_vs_projects.bat` to build from the command line



