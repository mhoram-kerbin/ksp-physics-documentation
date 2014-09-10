tagversion := $(shell git describe --tags | sed -e 's/^v\([0-9]\{1,\}[.][0-9]\{1,\}-[0-9]\{1,\}\)-.*/\1/g' | sed -e 's/v//' | sed -e 's/-/./')
fileversion := $(shell git describe --tags | sed -e 's/^v\([0-9]\{1,\}[.][0-9]\{1,\}-[0-9]\{1,\}\)-.*/\1/g' | sed -e 's/v//' | sed -e 's/[.]/-/g')

ksp-physics.pdf: ksp-physics.tex
	echo $(tagversion) > .tagversion
	latexmk -pdf ksp-physics.tex
	latexmk -c ksp-physics.tex
	cp ksp-physics.pdf ksp-physics-$(fileversion).pdf

clean:
	latexmk -c ksp-physics.tex
	rm -f *.pdf .tagversion test %ver%
