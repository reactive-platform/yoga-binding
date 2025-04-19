@echo on

mkdir bin
cmake -G Ninja -B bin
cmake --build bin

mkdir build
for %%f in (bin\lib*.dll) do copy "%%f" "build\"

@echo Build finished.