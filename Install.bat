call configure.bat
mkdir build
cmake -S ./compile -B ./build
MSBuild.exe ./build/MyRayTracer.sln /property:Configuration=Release
call build.bat
move .\build\Release\MyRayTracer.exe
rmdir .\build /s /q