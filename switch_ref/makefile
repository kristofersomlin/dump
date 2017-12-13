C_COMPILER=gcc
TEST_FILE=test.c
MAIN_FILE=main.c
FILE_TO_TEST=func.c
UNITY_PATH_AND_FILE=unity/src/unity.c
build:
				${C_COMPILER} ${TEST_FILE} ${FILE_TO_TEST} ${UNITY_PATH_AND_FILE} -o test.exe
				${C_COMPILER} ${MAIN_FILE} ${FILE_TO_TEST} ${UNITY_PATH_AND_FILE} -o calc.exe
