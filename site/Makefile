
DOXYGEN=/home/erik/doxygen-1.8.7/bin/doxygen

all : quantlibaddin.doxy
	$(DOXYGEN) quantlibaddin.doxy
	cp tabs.css html
	cp ql.css html
	mkdir -p html/images
	#cp -r images html
	cp -f images/*.ico images/*.jpg images/*.png html/images

clean :
	rm -rf html

