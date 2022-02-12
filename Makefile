BUILD_DIR=build

.PHONY: init clean

init:
	git submodule update --init --recursive

clean:
	rm -rf ${BUILD_DIR}