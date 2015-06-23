#DX_INCLUDE = "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Include"
#DX_LIB =     "C:\Program Files (x86)\Microsoft DirectX SDK (June 2010)\Lib\x86"

all:
	g++ -m32 -I$(DX_INCLUDE) -L$(DX_LIB) paperengine.cpp \
		--input-charset=utf-8 --exec-charset=cp932 -ld3d9 -ld3dx9_43 \
		-static -static-libstdc++ -static-libgcc -ldinput8 -ldsound -ldxguid -Wl,-subsystem,windows
