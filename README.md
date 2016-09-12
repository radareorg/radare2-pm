R2PM
====

The radare2 plugin/package database for r2pm

Allows to install, update, uninstall and discover plugins
and tools that can be used with radare2.

See https://github.com/radare/radare2 for r2pm

Testing new packages
--------------------

	export R2PM_DBDIR="$PWD/db"
	# export R2PM_GITDIR="/path/to/the/root/folder/of/the/local/repository"
	# export R2PM_USRDIR="/path/to/usr/dir"
	
	r2pm -i acr


TODO
----
* Add support to install binaries
   (useful for windows)
* Support to install more than one package
* Register where are the packages installed (prefix/home)
