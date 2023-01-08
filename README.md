# R2PM

This repository is fetched by `r2pm -U` and provides the package database.

These packages are installed in user's home and can be plugins/scripts
for radare2 or even utilities/programs related to r2.

See https://github.com/radareorg/radare2 for r2pm

## How to use

```sh
$ r2pm -U
$ r2pm -ci r2frida
```

## Testing new packages

```sh
export R2PM_DBDIR="$PWD/db"
# export R2PM_GITDIR="/path/to/the/root/folder/of/the/local/repository"
# export R2PM_USRDIR="/path/to/usr/dir"
```
