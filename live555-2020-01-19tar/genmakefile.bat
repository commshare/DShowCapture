#C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools


call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\Common7\Tools\vsdevcmd" -arch=x86

cd live

call genWindowsMakefiles

cd liveMedia
del *.obj *.lib
nmake /B -f liveMedia.mak
cd ..\groupsock
del *.obj *.lib
nmake /B -f groupsock.mak
cd ..\UsageEnvironment
del *.obj *.lib
nmake /B -f UsageEnvironment.mak
cd ..\BasicUsageEnvironment
del *.obj *.lib
nmake /B -f BasicUsageEnvironment.mak

pause