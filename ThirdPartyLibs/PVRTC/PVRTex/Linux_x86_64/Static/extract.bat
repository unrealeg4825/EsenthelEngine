rmdir /s /q build
mkdir build\Release
cd build\Release
..\..\..\..\..\..\..\Engine\Android\cygwin\ar.exe -x ..\..\libPVRTexLib.a
cd ..\..