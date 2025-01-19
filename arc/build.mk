# CFLAGS for module 'bar'
CFLAGS_bar := 

# Executable to build in module 'bar'
arc_PROGRAM := bar

# Libraries that the executable depends on:
arc_LIBRARIES := libbaz.a

# Sources for the executable 'bar' (without headers)
bar_SOURCES := interface.c main.c