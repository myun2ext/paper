
all:
	g++ -I$(DX_INCLUDE) -L$(DX_LIB) paperengine.cpp --input-charset=utf-8 --exec-charset=cp932 -ld3d9 -ld3dx9_43 -ldinput8 -ldxguid -Wl,-subsystem,windows
