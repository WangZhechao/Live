rm build_psv
mkdir build_psv && cd build_psv
cmake .. -DRUN_WIN32_PLATFORM=OFF
make