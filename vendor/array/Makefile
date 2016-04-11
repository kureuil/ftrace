##
## Makefile for nmobjdump in /home/louis/work/sysunix/PSU_2015_nmobjdump/nm
##
## Made by Louis Person
## Login   <person_l@epitech.net>
##
## Started on  Mon Feb 15 09:43:26 2016 Louis Person
## Last update Mon Mar 07 20:54:00 2016 Louis Person
##

AR			= ar rc

CP			= cp -rf

ECHO			= /bin/echo -e

TYPE			= "bin"

COLORGREEN		= "\e[32m"
COLORTEAL		= "\e[36m"
COLORBLUE		= "\e[94m"
COLORRED		= "\e[91m"
COLORRESET		= "\e[0m"

INSTALLDIR		?= .

MKDIR			= mkdir -p

PWD			= $(shell pwd)

VENDOR			= vendor/

CFLAGS			+= -Wall
CFLAGS			+= -Wextra
CFLAGS			+= -Wpedantic
CFLAGS			+= -Wstrict-overflow
CFLAGS			+= -I ./inc/
CFLAGS			+= -std=gnu99
CFLAGS			+= -D_DEFAULT_SOURCE
CFLAGS			+= -march=native
CFLAGS			+= -O2
CFLAGS			+= -fno-strict-aliasing

ISRCS			= $(SRCS)

OBJS			= $(ISRCS:%.c=%.o)
GCNO			= $(ISRCS:%.c=%.gcno)
GCDA			= $(ISRCS:%.c=%.gcda)

DEPS			= Makefile.deps

DEPSBIN			= tools/deps.sh

COVBIN			= tools/coverage.sh

LIBSFILES		= $(foreach lib,$(LIBS),$(notdir $(lib)))

LDFLAGS			+= -L ./lib/
LDFLAGS			+= -l merged

MAINSRC			= src/main.c

TSTNAME			= test_$(NAME)

CMOCKA_LIBRARY_PATH	= /usr/local/lib

include config.mk

ifeq ($(CC),"clang")
    CFLAGS		+= -Wno-gnu-zero-variadic-macro-arguments
endif

ifeq ($(TYPE),"lib")
    NAME		?= lib$(LIBNAME).a
endif

$(TSTNAME): CC=gcc
$(TSTNAME): CFLAGS += -D_UTEST_
$(TSTNAME): CFLAGS += -fprofile-arcs
$(TSTNAME): CFLAGS += -ftest-coverage
$(TSTNAME): LDFLAGS += -l gcov
$(TSTNAME): LDFLAGS += --coverage
$(TSTNAME): LDFLAGS += -l cmocka
$(TSTNAME): ISRCS := $(filter-out $(MAINSRC),$(SRCS))
$(TSTNAME): ISRCS += $(TSTSRCS)

all: $(NAME)

-include rules.mk

release: all

debug: all

ifeq ($(TYPE),"bin")
    $(NAME): $(LIBS) $(OBJS)
	@$(ECHO) $(COLORTEAL)"\t[AR] Merging libraries"$(COLORRESET)
	@$(RM) lib/libmerged.a
	@ar rcT lib/libmerged.a $(LIBS)
	@$(ECHO) $(COLORTEAL)"\t[LD] $@"$(COLORRESET)
	@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)
else
    $(NAME): $(OBJS)
	@$(ECHO) $(COLORTEAL)"\t[AR] $@"$(COLORRESET)
	@$(AR) $(NAME) $(OBJS)
endif

ifeq ($(TYPE),"bin")
install:
	@$(MKDIR) $(INSTALLDIR)/bin
	@$(ECHO) $(COLORBLUE)"\t[CP] $(NAME)"$(COLORRESET)
	@$(CP) $(NAME) $(INSTALLDIR)/bin
else
install:
	@$(MKDIR) $(INSTALLDIR)/lib
	@$(MKDIR) $(INSTALLDIR)/inc/$(LIBNAME)
	@$(ECHO) $(COLORBLUE)"\t[CP] $(NAME)"$(COLORRESET)
	@$(CP) $(NAME) $(INSTALLDIR)/lib
	@$(ECHO) $(COLORBLUE)"\t[CP] $(INCLUDES)"$(COLORRESET)
	@$(CP) $(INCLUDES) $(INSTALLDIR)/inc/$(LIBNAME)
endif

$(TSTNAME): clean
	@CFLAGS="$(CFLAGS)" CC="$(CC)" $(MAKE) $(OBJS) $(LIBS)
	@$(ECHO) $(COLORTEAL)"\t[LD] $@"$(COLORRESET)
	@$(RM) lib/libmerged.a
	@ar rcT lib/libmerged.a $(LIBS)
	@$(CC) -o "$(TSTNAME)" $(OBJS) $(LDFLAGS)
	@LD_LIBRARY_PATH=$(CMOCKA_LIBRARY_PATH) ./$(TSTNAME)
	@$(COVBIN) $(filter-out $(MAINSRC),$(SRCS))

test: $(TSTNAME)

clean:
	@$(ECHO) $(COLORRED)"\t[RM] $(OBJS)"$(COLORRESET)
	@$(RM) $(OBJS) $(TSTSRCS:%.c=%.o) $(GCNO) $(GCDA)

fclean: clean
	@$(ECHO) $(COLORRED)"\t[RM] $(NAME)"$(COLORRESET)
	@$(RM) $(NAME)
	@$(ECHO) $(COLORRED)"\t[RM] $(LIBS)"$(COLORRESET)
	@$(RM) $(LIBS)

%.a:
	@INSTALLDIR=$(PWD) $(MAKE) -C $(VENDOR)/$(@F:lib%.a=%) all install

%.o: %.c
	@$(ECHO) $(COLORGREEN)"\t[CC] $< -> $@"$(COLORRESET)
	@$(CC) -c -o $@ $(CFLAGS) $<

re: fclean all

DEPSCMD		:= $(shell $(DEPSBIN) $(SRCS) > $(DEPS))

-include overrides.mk

-include $(DEPS)

.PHONY: all install clean fclean re test $(TSTNAME)
