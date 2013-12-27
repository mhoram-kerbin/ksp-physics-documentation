ksp-physics.pdf: ksp-physics.tex .tagversion
	latexmk -pdf ksp-physics.tex
	latexmk -c ksp-physics.tex

.tagversion:
	git describe --tags | sed -e 's/^\([0-9]\{1,\}[.][0-9]\{1,\}-[0-9]\{1,\}\)-.*/\1/g' > .tagversion

clean:
	rm -f ksp-physics.pdf .tagversion
