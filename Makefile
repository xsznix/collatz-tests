TMPFILES := $(patsubst %.in,%.tmp,$(wildcard *-RunCollatz.in))

test: $(TMPFILES)

%.tmp: %.in %.out ../RunCollatz
	../RunCollatz < $< > $@
	diff $@ $(word 2,$^)
