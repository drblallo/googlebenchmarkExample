# benchmark setup

A easy setup for google test and google benchmark

## usage

```bash
	git submodule update --recursive --init
	source environement.sh
	mkdir release
	cd release
	cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install .. 
	make all
	make install
	./install/benchmark/utilsBenchmark	
```

the benchmark source file is in lib/utils/benchmark/src
