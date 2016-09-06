@echo ==================================
@echo SET VisualStudio PATH
@echo ==================================
call "%VS110COMNTOOLS%\vsvars32.bat

@echo ==================================
@echo Clean VisualStudio Solution
@echo ==================================
devenv DllTest.sln /Clean Debug
devenv DllTest.sln /Clean Release
rmdir Debug /s /q
rmdir Release /s /q
rmdir CreateDll\Debug /s /q
rmdir CreateDll\Release /s /q
rmdir CheckDll\Debug /s /q
rmdir CheckDll\Release /s /q
del *.sdf
del *.log
rmdir ipch /s /q

PAUSE