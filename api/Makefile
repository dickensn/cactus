rootPath = ../
include ../include.mk

libSources = impl/cactus*.c
libHeaders = inc/cactus*.h
libInternalHeaders = impl/*.h
libTests = tests/cactus*.c
libTestsHeaders = tests/cactus*.h

all : ${libPath}/cactusLib.a ${binPath}/cactusAPITests 

clean : 
	rm -f ${libPath}/cactusLib.a ${libPath}/cactus*.h ${binPath}/cactusAPITests

${libPath}/cactusLib.a : ${libSources} ${libHeaders} ${libInternalHeaders} ${basicLibsDependencies}
	cp ${libHeaders} ${libPath}/
	${cxx} ${cflags} -I inc -I ${libPath}/ -c ${libSources}
	ar rc cactusLib.a *.o
	ranlib cactusLib.a 
	rm *.o
	mv cactusLib.a ${libPath}/
	
${binPath}/cactusAPITests : ${libTests} ${libTestsHeaders} ${libSources} ${libHeaders} ${libInternalHeaders} tests/allTests.c ${libPath}/cactusLib.a ${basicLibsDependencies}
	${cxx} ${cflags} -I inc -I ${libPath} -I impl -I tests -o ${binPath}/cactusAPITests tests/allTests.c ${libTests} ${libPath}/cactusLib.a ${basicLibs}
