
## make -n This will show what make is attempting to do.
## The -d option might help but will give you an extremely long output.
## make -p will also interest you, which prints the values of set variables.
##
## $(patsubst pattern,replacement,text)
## 	Finds whitespace-separated words in text that match pattern and replaces them with replacement. 
## 	Here pattern may contain a ‘%’ which acts as a wildcard, matching any number of any characters within a word. If replacement also 
##  contains a ‘%’, the ‘%’ is replaced by the text that matched the ‘%’ in pattern. Only the first ‘%’ in the pattern and replacement is treated this way; any subsequent ‘%’ is unchanged.
##
## $(filter pattern…,text)
## Returns all whitespace-separated words in text that do match any of the pattern words, removing any words that do not match. 
### The patterns are written using ‘%’, just like the patterns used in the patsubst function above.
###
### VPATH = Thus, if a file that is listed as a target or prerequisite does not exist in the current directory, make searches the directories listed in VPATH for a file with that name. 
### Similar to the VPATH variable, but more selective, is the vpath directive (note lower case), which allows you to specify a search path for a particular class of file names
### vpath %.h ../headers
### vpath %.c foo
### vpath %   blish
### vpath %.c bar
###
### targets …: target-pattern: prereq-patterns …
### The target-pattern and prereq-patterns say how to compute the prerequisites of each target. 
### The prerequisite names for each target are made by substituting the stem for the ‘%’ in each prerequisite pattern. 
### For example, if one prerequisite pattern is %.c, then substitution of the stem ‘foo’ gives the prerequisite name foo.c
###
### Thus, a pattern rule ‘%.o : %.c’ says how to make any file stem.o from another file stem.c.
### ‘%’ in a prerequisite of a pattern rule stands for the same stem that was matched by the ‘%’ in the target. In order for the pattern rule to apply, its target pattern must match the file name under consideration and all of its prerequisites (after pattern substitution) must name files that exist or can be made. These files become prerequisites of the target.
### Thus, a rule of the form
### 
### %.o : %.c ; recipe…
### specifies how to make a file n.o, with another file n.c as its prerequisite, provided that n.c exists or can be made.
### There may also be prerequisites that do not use ‘%’; such a prerequisite attaches to every file made by this pattern rule.
### A pattern rule need not have any prerequisites that contain ‘%’, or in fact any prerequisites at all. Such a rule is 
### effectively a general wildcard. It provides a way to make any file that matches the target pattern.
###
### First, the rule that compiles ‘.c’ files into ‘.o’ files:
###
### %.o : %.c
###        $(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@
### defines a rule that can make any file x.o from x.c. The recipe uses the automatic variables ‘$@’ and ‘$<’ to substitute the names 
### of the target file and the source file in each case where the rule applies (see Automatic Variables).
### 
### Here is a second built-in rule:
### 
### % :: RCS/%,v
###         $(CO) $(COFLAGS) $<
### defines a rule that can make any file x whatsoever from a corresponding file x,v in the sub-directory RCS. Since the target is ‘%’, 
### this rule will apply to any file whatever, provided the appropriate prerequisite file exists. The double colon makes the rule terminal, which
### means that its prerequisite may not be an intermediate file
### 
### <<How Patterns Match>>
###
### A target pattern is composed of a ‘%’ between a prefix and a suffix, either or both of which may be empty. The pattern matches a file name 
### only if the file name starts with the prefix and ends with the suffix, without overlap. The text between the prefix and the suffix is called the stem. 
### Thus, when the pattern ‘%.o’ matches the file name test.o, the stem is ‘test’. The pattern rule prerequisites are turned into actual file names 
### by substituting the stem for the character ‘%’. Thus, if in the same example one of the prerequisites is written as ‘%.c’, it expands to ‘test.c’.
###
### lib/%.o: lib/%.c
###		$(CC) -fPIC -c $(CFLAGS) $(CPPFLAGS) $< -o $@
### $(patsubst pattern,replacement,$(var))
### $(patsubst %.o,%.c,$(objects))
### $(patsubst %.c,%.o,x.c.c bar.c)  produces the value ‘x.c.o bar.o’.
### $(filter pattern…,text)
### sources := foo.c bar.c baz.s ugh.h
### foo: $(sources)
###		cc $(filter %.c %.s,$(sources)) -o foo
###
### $(sort list)
### $(sort foo bar lose)
###
###	First, the subst function is used to change the colons to spaces::
###	$(subst :, ,$(VPATH))
###
### override CFLAGS += $(patsubst %,-I%,$(subst :, ,$(VPATH)))
###
### $(dir src/foo.c hacks)		produces the result ‘src/ ./’
### $(suffix names…)			produces the result ‘.c .c’.
### $(basename src/foo.c src-1.0/bar hacks) produces the result ‘src/foo src-1.0/bar hacks’.
### $(addsuffix .c,foo bar)		produces the result ‘foo.c bar.c’.
### $(addprefix src/,foo bar)	produces the result ‘src/foo src/bar’
### $(join list1,list2)
### $(wildcard pattern)
### $(if condition,then-part[,else-part])
### $(or condition1[,condition2[,condition3…]])
### $(and condition1[,condition2[,condition3…]])


.PHONY = all 

CC = g++
ROOT = $(shell pwd)
APPS += hello
APPS += anil


##### set the objects 
OUTPUT_OPTION = -o objects/$@

##### Include all the modules inc
MODULEINCS = $(shell find . -name *.inc)
include $(MODULEINCS)

##### standard makefile flags
CXXFLAGS = $(sort $(foreach module, $(PROJECT_MODULES), -I$($(module)_INCLUDES) ))
CXXFLAGS += -g



##### get the all the sources
SOURCES = $(sort $(foreach sources, $(PROJECT_MODULES), $($(sources)_SOURCES)))
SOURCES += hello.cpp

##### get all the objects to be created from the sources
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
OBJS += $(SOURCES:.cpp=.o)
DEPS += $(OBJS:.o=.d)

apps: $(APPS)
	
$(APPS): clean checkbuildvariables $(OBJS)
	@echo "*="$* "^="$^  "?="$?  "<="$<  "%="$%  "@="$@
	g++ $(OBJS) -o $@
	@echo " "
	@echo "*******  Running the test app*******"
	@echo " "
	./$@
	
##### Print out the build variables	
checkbuildvariables:
	@echo "<<<<< PROJECT_MODULES >>>>>>"
	@echo $(PROJECT_MODULES)	
	@echo " "
	@echo "<<<<< MODULE INCS >>>>>"
	@echo $(MODULEINCS)
	@echo " "
	@echo "<<<<< CXXFLAGS >>>>>"
	@echo $(CXXFLAGS)
	@echo " "
	@echo "<<<<< SOURCES >>>>>"
	@echo $(SOURCES)
	@echo " "
	@echo "<<<<< OBJS >>>>>"
	@echo $(OBJS)
	@echo " "
	@echo "<<<<< DEPS >>>>>"
	@echo $(DEPS)
	@echo " "
	@echo "<<<<< Checking ROOT >>>>>"
	ls $(ROOT)
	@echo " "

##### Help of all the make variables
help:
	@echo $(wildcard *.cpp)
	@echo $(patsubst %.cpp,%.o,$(wildcard *.cpp))
	@echo $(OBJECTS)
	@echo checkbuildvariables, help
	

##### pull in dependency info for *existing* .o files
-include $(OBJS:.o=.d)


##### compile and generate dependency info
## $* The stem of the target filename. A stem is typically a filename without its suffix. 
## filter function to remove non-matching file names i.e names that are not objects.

$(filter %.o,$(OBJS)): %.o: %.cpp
	@echo "-----------------------------------------------------------------------"
	@echo "Names of all prerequisites="$^
	@echo "Names of all prerequisites that are newer than the target="$?
	@echo "Stem of the target="$*
	@echo "Current target="$@
	g++ -c $(CXXFLAGS) $*.cpp -o $*.o
	@echo ""
	g++ -MM $(CXXFLAGS) $*.cpp > $*.d
	@echo "-----------------------------------------------------------------------"
	
##### PROJECT_INCLUDES	
PROJECT_INCLUDES := $(CXXFLAGS)

##### remove compilation products
clean:
	rm -vf hello $(OBJS) $(DEPS) *.o 