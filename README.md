# P2P-Cpp-Library
A pure c++ library with build system cmake for peer to peer connection using Tcp/Ip sockets.

## Directory structure

- `peer/` contains the peer classes
- `tests/` contain the sample examples
- `peermessages/` contains the messages handeling that arrive on a peer


## Dependencies
No dependency required

## Build

Make sure you have `cmake` installed and it is available in the path.

First clone the repo:

```
git clone https://github.com/UmarFarooq-MP/P2P-Cpp-Library.git
```

Build **Unix/Mac**:

```bash
mkdir build && cd build && cmake .. && make -j4
```

Build on **Windows**:

Currently only TDM-MinGW64 is supported. MSVC has not been tested but should work.

```bash
mkdir build && cd build
cmake -G"MinGW Makefiles" ..
mingw32-make
```

**Note**: This library is work in progress.
