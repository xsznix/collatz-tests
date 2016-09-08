TMPFILES := $(patsubst %.in,%.tmp,$(wildcard *-RunCollatz.in))

.PHONY: all
all:
	python verify.py -r

test: $(TMPFILES)

%.tmp: %.in %.out ../RunCollatz
	../RunCollatz < $< > $@
	diff $@ $(word 2,$^)

.PHONY: clean
clean:
	rm *.tmp

.PHONY: check
check:
	python verify.py
