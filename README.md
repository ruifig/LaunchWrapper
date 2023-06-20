
# Very simple application launch wrapper.

I've created this little utility to simply launch another process passing the original parameters AND any defined extra parameters.
My use case was that when testing a Steam game I wanted that installed Steam game to actually launch another game, passing whatever parameters Steam is adding AND any extra parameters I want.

What it does:

* Looks for a LaunchWrapper.ini in the same directory as the executable. The following is expected from the ini file:
	* **REQUIRED:** A `process=<PATH>` value, which is the full path to the process to launch. This process will be launched with all the parameters passed to LaunchWrapper
		* The hardcoded `none` (case sensitive) process name is accepted, and if specified  it will not spawn any process and will simply return an exit code 0 (Sucess)
	* **OPTIONAL:** A `params_extra` value, which specifies extra parameters to be passed to the launched process.



# How to build

* Clone
* Run `gen_vs_projects.bat`. It will download dependencies and generate VS projects
* Optionally, run `build_release.bat` after `gen_vs_projects.bat` to build from the command line


# How to use

* Place the LaunchWrapper executable in whatever folder you want it to be, and rename it to whatever you want
* Create a `LaunchWrapper.ini` file in the same folder as the executable. Note that this ini file needs to be named `LaunchedWrapper.ini`, and NOT what you renamed the executable to.
	* Add a `process` value that points to the process you want to launch
	* Add a `extra_params` value with any extra parameters

For example, this `LaunchWrapper.ini` file will launch ping.exe adding the extra parameters `-l 512`:

```
; Full path to the process to launch
; This can be set to "none" (without quotes), in which case the wrapper won't do anything
; Using just a silly example here 
process=C:\Windows\System32\PING.exe

; Extra parameters to pass to the process.
; These are added after original parameters passed to LaunchWrapper
; So, in this example, when calling say:
;		LaunchWrapper.exe localhost
; It will will effectively call:
;		PING.exe localhost -l 512	
extra_params=-l 512

; true/false or 1/0
; If 1, it will pause waiting waiting for a keypress once finished
;pause_on_finished=1

```

