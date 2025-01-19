default: run

.PHONY: all clean mrproper

AUXFILES := Makefile README.md 

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes

CFLAGS := -g -std=gnu99 $(WARNINGS)

MODULES := bootloader arc

CFLAGS_global := -MMD -I includes

ARFLAGS := rc

all:
    @echo "Default target."

define MK_template
include $(1)/build.mk
endef

define RULES_template
$(1)/obj/%.o: $(1)/src/%.c
	$$(CC) $$(CFLAGS) $$(CFLAGS_global) $$(CFLAGS_$(1)) -c $$< -o $$@
endef

define PROGRAM_template
DEPENDENCIES := $(DEPENDENCIES) $(patsubst %,$(2)/obj/%.d,$(basename $($(1)_SOURCES)))
bin/$(1): $(patsubst %,$(2)/obj/%.o,$(basename $($(1)_SOURCES))) $(foreach library,$($(1)_LIBRARIES),lib/$(library))
	$$(LD) $$(LDFLAGS) $$(LDFLAGS_$(2)) $$^ -o $$@
endef


define ARCHIVE_template
DEPENDENCIES := $(DEPENDENCIES) $(patsubst %,$(2)/obj/%.d,$(basename $($(1)_SOURCES)))
lib/$(1): $(patsubst %,$(2)/obj/%.o,$(basename $($(1)_SOURCES)))
	$$(AR) $$(ARFLAGS) $$@ $$?
endef

define INCLUDE_template
ifeq ($(wildcard includes/$(1)),)
    $$(shell ln -s ../$(1)/includes includes/$(1))
endif
endef

$(foreach module,$(MODULES),$(eval include $(module)/build.mk))
$(foreach module,$(MODULES),$(eval $(call RULES_template,$(module))))
$(foreach module,$(MODULES),$(eval $(foreach binary,$($(module)_PROGRAM),$(call PROGRAM_template,$(binary),$(module)))))
$(foreach module,$(MODULES),$(eval $(foreach library,$($(module)_ARCHIVE),$(call ARCHIVE_template,$(library),$(module)))))
$(foreach module,$(MODULES),$(eval $(call INCLUDE_template,$(module))))

-include $(sort $(DEPENDENCIES))

clean:
	$(RM) $(foreach mod,$(MODULES),$(mod)/obj/*.o)

mrproper: clean
	$(RM) $(foreach mod,$(MODULES),$(mod)/obj/*.d) includes/* bin/* lib/*