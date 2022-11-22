#!/bin/sh

echo "## Broken packages using global variables"
git grep '^[A-Z]*=' db |grep -v :R2PM |cut -d : -f1|sort -u

echo "## Wrongly indented packages (use tabs not spaces!)"
git grep '^ ' db |cut -d : -f 1 |sort -u

echo "## Packages without R2PM_END"
for a in db/* ; do git grep R2PM_END $a > /dev/null || echo $a ; done

echo "## Packages supported on Windows"
git grep R2PM_INSTALL_WINDOWS |cut -d : -f1|sort -u

echo "## Packages with XXX or TODO comments"
git grep -e TODO -e XXX db
