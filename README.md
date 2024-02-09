 Glut setup for Codeblocks (Don’t install Codeblocks 20.X version) <br>
Step-1: Download 17.12 Version from given link: <br>
https://sourceforge.net/projects/codeblocks/files/Binaries/17.12/Windows/codeblocks-17.12mingw-setup.exe/download

Step-2: <br>
1	Download glut-3.7.6-bin.zip <br>
2	Unzip the file. There will be at least 3 files. (glut.h, glut32.dll, glut32.lib)<br>
3	go location : C:\Program Files (x86)\CodeBlocks\MinGW\include\GL<br>
4	paste glut.h <br>
5	go location: C:\Program Files (x86)\CodeBlocks\MinGW\lib <br>
6	 	paste glut32.lib<br>
7	go C:\Windows\SysWOW64 <br>
8	paste glut32.dll<br>
Note: If your Operating System is 32 bit, Folder name might be C:\Windows\System32 for last step.<br>

Step-3:<br>
1 Linker settings for Codeblocks<br>
2 Codeblocks: Select settings -- select compiler -- linker settings-  press clear<br>
3 press add, go this location: C:\Program Files (x86)\CodeBlocks\MinGW\lib<br>
4 Then add: libglu32.a, libglut32.a or glut32.lib, libopengl32.a<br>
5 press ok<br>



