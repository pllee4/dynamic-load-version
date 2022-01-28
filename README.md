# dynamic-load-version

![build](https://github.com/pllee4/dynamic-load-version/actions/workflows/build.yml/badge.svg)

## Motivation
- This repo is inspired by [theo-pnv](https://blog.theopnv.com/posts/cpp-dynamic-loading/)
- Minimal example is shown for loading dynamic shared libraries

## Build and run
```
$ mkdir build
$ cd build/ && cmake ..
$ make -j
$ ./bin/app V1 # or ./bin/app V2
```