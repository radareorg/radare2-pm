R2PM_BEGIN

R2PM_GIT https://github.com/ggerganov/llama.cpp
R2PM_DESC "Advanced open-source language model implementation"

R2PM_NEEDS "gcc make cmake"

R2PM_INSTALL() {
	cmake -DCMAKE_INSTALL_PREFIX:PATH=${R2PM_PREFIX} -DCMAKE_CXX_FLAGS="-O2 -fPIC" -DCMAKE_SHARED_LINKER_FLAGS=-fPIC .
	${MAKE} -j4
	${R2PM_SUDO} ${MAKE} install
}

R2PM_UNINSTALL() {
	${R2PM_SUDO} ${MAKE} uninstall
}

R2PM_END
