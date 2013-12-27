tagversion := $(shell git describe --tags | sed -e 's/^\([0-9]\{1,\}[.][0-9]\{1,\}-[0-9]\{1,\}\)-.*/\1/g')

ksp-physics.pdf: ksp-physics.tex .tagversion
	latexmk -pdf ksp-physics.tex
	latexmk -c ksp-physics.tex
	ln ksp-physics.pdf ksp-physics-$(tagversion).pdf

.tagversion:
	echo $(tagversion) > .tagversion

clean:
	rm -f *.pdf .tagversion
