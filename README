# Test Repo Instructions

* Fork this repo, and on your fork, do the following:

* Add these lines to the Makefile, replacing "EID" with your eid:

```
EID-RunCollatz.tmp: ../RunCollatz
	../RunCollatz < EID-RunCollatz.in > EID-RunCollatz.tmp
	diff EID-RunCollatz.tmp EID-RunCollatz.out

EID-TestCollatz: EID-TestCollatz.c++ ../Collatz.h ../Collatz.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) ../Collatz.c++ EID-TestCollatz.c++ -o EID-TestCollatz $(LDFLAGS)
ifneq ($(shell uname -p), unknown)                                    # Docker
	-$(CLANG-CHECK) -extra-arg=-std=c++11          TestCollatz.c++ --
	-$(CLANG-CHECK) -extra-arg=-std=c++11 -analyze TestCollatz.c++ --
endif

EID-TestCollatz.tmp: EID-TestCollatz
	$(VALGRIND) ./EID-TestCollatz                        >  EID-TestCollatz.tmp 2>&1
	$(GCOV) -b ../Collatz.c++ | grep -A 5 "File 'Collatz.c++'" >> EID-TestCollatz.tmp
	cat EID-TestCollatz.tmp
```

* Add your new make targets (`EID-RunCollatz.tmp EID-TestCollatz.tmp`) to the `all` target.

* Add the requested files (EID-RunCollatz.in, EID-RunCollatz.out, EID-TestCollatz.c++, EID-TestCollatz.out) to this folder.

* Commit and push your code to your fork.

* Submit a pull request upstream to the main test repo.

* Edit these instructions and make them better!
