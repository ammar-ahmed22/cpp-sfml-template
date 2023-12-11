SRC_DIR = .
BUILD_DIR = build
PROJECT_NAME = Project

all: compile 
	@cmake --build ./build

compile: pre_build
	@cmake -S ${SRC_DIR} -B ./${BUILD_DIR}

pre_build:
	mkdir -p ${BUILD_DIR}

run:
	@./${BUILD_DIR}/${PROJECT_NAME}

clean:
	rm -rf ./${BUILD_DIR}
