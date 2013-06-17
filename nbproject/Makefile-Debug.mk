#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Face.o \
	${OBJECTDIR}/Mesh.o \
	${OBJECTDIR}/Vertice.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit
CXXFLAGS=-std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/boost_1_53_0/stage/lib -L/usr/local/lib/json-spirit/build -lboost_atomic -lboost_chrono -lboost_context -lboost_date_time -lboost_exception -lboost_filesystem -lboost_graph -lboost_locale -lboost_math_c99 -lboost_math_c99f -lboost_math_c99l -lboost_math_tr1 -lboost_math_tr1f -lboost_math_tr1l -lboost_prg_exec_monitor -lboost_program_options -lboost_python -lboost_random -lboost_regex -lboost_serialization -lboost_signals -lboost_system -lboost_test_exec_monitor -lboost_thread -lboost_timer -lboost_unit_test_framework -lboost_wave -lboost_wserialization -ljson_spirit

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/roberta

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/roberta: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/roberta ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Face.o: Face.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/boost_1_53_0 -I/usr/local/lib/json-spirit/include -std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit -MMD -MP -MF $@.d -o ${OBJECTDIR}/Face.o Face.cpp

${OBJECTDIR}/Mesh.o: Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/boost_1_53_0 -I/usr/local/lib/json-spirit/include -std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mesh.o Mesh.cpp

${OBJECTDIR}/Vertice.o: Vertice.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/boost_1_53_0 -I/usr/local/lib/json-spirit/include -std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vertice.o Vertice.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/boost_1_53_0 -I/usr/local/lib/json-spirit/include -std=c++0x -L /usr/local/boost_1_53_0/libs/ -L/usr/local/lib/json-spirit -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/roberta

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
