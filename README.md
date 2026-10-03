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

## Binary packages

Use `r2pm -bi r2frida` to install a released binary without cloning or compiling
sources. `R2V` selects the release and defaults to the installed radare2 version:

```sh
R2V=6.2.2 r2pm -bi r2frida
```

Packages provide `R2PM_BINSTALL()` for Unix shell commands and
`R2PM_BINSTALL_WINDOWS()` for Windows commands. These hooks run without a
source checkout, receive `R2V`, `R2PM_OS` (`linux`, `darwin`, `windows`, ...),
`R2PM_ARCH` (`x86`, `arm`, ...), `R2PM_BITS` (`32` or `64`) and `R2PM_TRIPLET`
(`<os>-<arch>-<bits>`, for example `linux-x86-64`), and install into
the usual `R2PM_PLUGDIR`, `R2PM_BINDIR` and other r2pm directories. `-g` selects
the system plugin directory and provides `R2PM_SUDO` on Unix.

Binary hooks must select the exact version and target, handle their own tools
and runtime dependencies, respect `R2PM_OFFLINE`, and return nonzero if the
binary is unavailable or installation fails. `R2PM_NEEDS` and `R2PM_DEPS` are
source-build prerequisites and are skipped. There is no source fallback: r2pm
reports the error and asks the user to re-run without `-b`.

The r2frida hooks extract Linux `.deb`, macOS `.pkg`, and Windows `.zip` release
assets into the r2pm directories. Availability depends on the selected release;
missing architectures or versions fail rather than using a different release.
