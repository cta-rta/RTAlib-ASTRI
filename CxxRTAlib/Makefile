# ==========================================================================
#
# Copyright (C) 2018 Leonardo Baroncelli
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ==========================================================================

################################################################################
# Shell
#
SHELL = /bin/sh

################################################################################
# External dependencies
#
ifndef RTALIB
$(error RTALIB is not set.)
endif
ifndef REDIS
$(error REDIS is not set.)
endif
ifndef MYSQL_CXX_CNT
$(error MYSQL_CXX_CNT is not set.)
endif
ifndef BOOST_PATH
$(error BOOST_PATH is not set.)
endif
ifndef CTA_ALGORITHMS
$(error CTA_ALGORITHMS is not set.)
endif
ifndef CTA_UTILS
$(error CTA_UTILS is not set.)
endif
ifndef GTEST_DIR
$(error GTEST_DIR is not set.)
endif



################################################################################
# Utilities
#
AR       = ar cqs
TAR      = tar -cf
GZIP     = gzip -9f
COPY     = cp -f -r
COPY_FILE= $(COPY) -p
COPY_DIR = $(COPY) -pR
DEL_FILE = rm -f
DEL_FOLDER = rm -r
SYMLINK  = ln -sf
DEL_DIR  = rm -rf
MOVE     = mv -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p	# -p


################################################################################
# Project name and system
#
PROJECT=RTAlib-ASTRI
SYSTEM= $(shell gcc -dumpmachine)



################################################################################
#	Sources (RTAlib-ASTRI)
#
SOURCE_DIR_CXX_DM = astri_CxxRTAlib/DataModels/src_cpp
SOURCE_DIR_CXX_RTA = astri_CxxRTAlib/RTAInterface/src_cpp

################################################################################
#	Unit test source (RTAlib-ASTRI)
#
SOURCE_DIR_CXX_UNIT_TEST = TestEnvironment/src_cpp/astri_unitTest.cpp

################################################################################
#	Headers (RTAlib-ASTRI)
#
INCLUDE_DIR_CXX_DM = astri_CxxRTAlib/DataModels/include_cpp
INCLUDE_DIR_CXX_RTA = astri_CxxRTAlib/RTAInterface/include_cpp

#####################################
# Headers (RTAlib)
#
INCLUDE_DIR_CXXLIB_DM = $(RTALIB)/CxxRTAlib/CxxRTAlib/DataModels/include_cpp

INCLUDE_DIR_CXX_DBC = $(RTALIB)/CxxRTAlib/CxxRTAlib/DBConnectors/include_cpp
INCLUDE_DIR_C_DBC = $(RTALIB)/CxxRTAlib/CxxRTAlib/DBConnectors/include_c

INCLUDE_DIR_CXXLIB_RTA = $(RTALIB)/CxxRTAlib/CxxRTAlib/RTAInterface/include_cpp

INCLUDE_DIR_CXX_U = $(RTALIB)/CxxRTAlib/CxxRTAlib/Utils/include_cpp
INCLUDE_DIR_C_U = $(RTALIB)/CxxRTAlib/CxxRTAlib/Utils/include_c



################################################################################
# Objects
#
OBJECTS_DIR = astri_CxxRTAlib/obj_cpp


################################################################################
# Outputs
#
LIB_DESTDIR = lib
LIB_NAME = libastri_cxxrtalib.a
UNITTEST_EXE_DESTDIR = TestEnvironment/bin
UNITTEST_EXE = unitTest


################################################################################
# Compiler and compilation flags (C++)
#
CXX = g++

CXXFLAGS = -O3 -funroll-loops -std=c++11 -lpthread

CXXFLAGS += -I$(INCLUDE_DIR_CXXLIB_DM) \
 						-I$(INCLUDE_DIR_CXXLIB_RTA) \
						-I$(INCLUDE_DIR_CXX_DM) \
						-I$(INCLUDE_DIR_CXX_RTA) \
						-I$(INCLUDE_DIR_CXX_U) \
						-I$(INCLUDE_DIR_C_U) \
						-I$(INCLUDE_DIR_C_DBC) \
						-I$(INCLUDE_DIR_CXX_DBC)

CXXFLAGS += -I$(REDIS)

CXXFLAGS += -I$(CTA_ALGORITHMS)/code

CXXFLAGS += -I$(CTA_UTILS)/code

CXXFLAGS += -I$(MYSQL_CXX_CNT)/include

CXXFLAGS += -I$(BOOST_PATH)

CXXFLAGS += -Wl,-Bdynamic

CXXFLAGS += -I/usr/local/include/cppconn

GTEST_HEADERS =   $(GTEST_DIR)/include/ \
							  -I$(GTEST_DIR)/include/gtest/internal/*.h

# Flags passed to the preprocessor. Set Google Test's header directory as a system directory, such that the compiler doesn't generate warnings in Google Test headers.
GTEST_SYSTEM += -isystem $(GTEST_DIR)/include

CXXFLAGS += $(GTEST_SYSTEM)

CXXFLAGS += -I$(GTEST_HEADERS)



################################################################################
# Linking
#
LIBS += -L$(RTALIB)/CxxRTAlib/lib -lcxxrtalib

LIBS += -L$(MYSQL_CXX_CNT)/lib64/debug -lmysqlcppconn8

LIBS += -L$(REDIS)/ -lhiredis

LIBS += -L$(CTA_ALGORITHMS)/lib -lCTAAlgorithms

LIBS += -L$(CTA_UTILS)/lib -lCTAUtils

LIBS += -L$(REDIS) -lhiredis

LIBS += -L$(GTEST_DIR)/lib64 -lgtest



################################################################################
# Debugging configuration
#
ifeq ($(DEBUG),1)
	CXXFLAGS += -DDEBUG
endif
ifeq ($(VALGRIND),1)
	CXXFLAGS += -g -O0
endif




################################################################################
# VPATH
#
VPATH=$(SOURCE_DIR_CXX_DM):$(INCLUDE_DIR_CXX_DM):$(SOURCE_DIR_CXX_RTA):$(INCLUDE_DIR_CXX_RTA)
vpath %.o $(OBJECTS_DIR)


################################################################################
# Objects generation (C++)
#
SOURCE_CXX+=$(foreach dir,$(SOURCE_DIR_CXX_DM), $(wildcard $(dir)/*.cpp))
SOURCE_CXX+=$(foreach dir,$(SOURCE_DIR_CXX_RTA), $(wildcard $(dir)/*.cpp))

OBJECTS=$(addsuffix .o, $(basename $(notdir $(SOURCE_CXX))))


################################################################################
# Logs
#
#$(info $$INCLUDE_CXX is [${INCLUDE_CXX}])
#$(info $$SOURCE_CXX is [${SOURCE_CXX}])
$(info $$OBJECTS is [${OBJECTS}])



################################################################################
# Pattern rules
#
%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(OBJECTS_DIR)/$@

%.o : %.c
	$(C) $(CFLAGS) -c $< -o $(OBJECTS_DIR_C)/$@



################################################################################
# Rules
#
all: staticlib #unittest

makeobjdir:
	test -d $(OBJECTS_DIR) || mkdir -p $(OBJECTS_DIR)

makelibdir:
	test -d $(LIB_DESTDIR) || mkdir -p $(LIB_DESTDIR)

makeexedir:
	test -d $(UNITTEST_EXE_DESTDIR) || mkdir -p $(UNITTEST_EXE_DESTDIR)


staticlib: makelibdir makeobjdir  $(OBJECTS)
		test -d $(LIB_DESTDIR) || mkdir -p $(LIB_DESTDIR)
		$(AR) $(LIB_DESTDIR)/$(LIB_NAME) $(OBJECTS_DIR)/*.o


unittest: makeexedir
	$(CXX) $(SOURCE_DIR_CXX_UNIT_TEST) $(CXXFLAGS) -o $(UNITTEST_EXE_DESTDIR)/$(UNITTEST_EXE) $(OBJECTS_DIR)/*.o $(LIBS)

clean:
	$(DEL_FILE) $(OBJECTS_DIR)/*.o
	$(DEL_FILE) $(OBJECTS_DIR_C)/*.o
	$(DEL_FILE) $(LIB_DESTDIR)/*
	#$(DEL_FILE) $(UNITTEST_EXE_DESTDIR)/*
