DX_INCLUDE = "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include"
DX_LIB =     "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Lib\x86"

all:
	g++ -I$(DX_INCLUDE) -L$(DX_LIB) paperengine.cpp -ld3d9 -ld3dx9_43 -Wl,-subsystem,windows
input:
	g++ -I$(DX_INCLUDE) -L$(DX_LIB) input.cpp -ld3d9 -ldinput8 -ldxguid -Wl,-subsystem,windows
