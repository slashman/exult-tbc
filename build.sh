
SDK=' -w -isysroot /Users/slash/oldhd/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk/ -mmacosx-version-min=10.7 '
export MACOSX_DEPLOYMENT_TARGET=10.7
export PATH=/opt/local/bin/:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin
export CC="/usr/bin/clang"
export CXX="/usr/bin/clang++"
export CPPFLAGS='-I/opt/local/include '$SDK
export CFLAGS='-I/opt/local/include '$SDK
export CXXFLAGS='-I/opt/local/include '$SDK
export LDFLAGS='-L/opt/local/lib '$SDK
export PKG_CONFIG_PATH="/opt/local/lib/pkgconfig"
export PKG_CONFIG=/opt/local/bin/pkg-config
export LIBTOOLFLAGS="--silent"
./autogen.sh
./configure --with-sdl=sdl2 --enable-debug
make clean > /dev/null
make -j9 -s