 Glut setup for Codeblocks (Don’t install Codeblocks 20.X version)
Step-1: Download 17.12 Version from given link:
https://sourceforge.net/projects/codeblocks/files/Binaries/17.12/Windows/codeblocks-17.12mingw-setup.exe/download

Step-2: 
	Download glut-3.7.6-bin.zip 
	Unzib the file. There will be at least 3 files. (glut.h, glut32.dll, glut32.lib)
	go location : C:\Program Files (x86)\CodeBlocks\MinGW\include\GL
o	paste glut.h 
	go location: C:\Program Files (x86)\CodeBlocks\MinGW\lib 
	 	paste glut32.lib
	go C:\Windows\SysWOW64 
o	paste glut32.dll
Note: If your Operating System is 32 bit, Folder name might be C:\Windows\System32 for last step.

Step-3:
Linker settings for Codeblocks
Codeblocks: Select settings -- select compiler -- linker settings-  press clear
press add, go this location: C:\Program Files (x86)\CodeBlocks\MinGW\lib
Then add: libglu32.a, libglut32.a or glut32.lib, libopengl32.a
press ok



