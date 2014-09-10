ksp-physics.pdf: ksp-physics.tex
	latexmk -enable-write18 -pdf ksp-physics.tex
	cp ksp-physics.pdf ksp-physics-$$(cat .tagversion | sed -e 's/[.]/-/g').pdf

cleanpdf:
	rm -f *.pdf

clean: cleanpdf
	latexmk -c ksp-physics.tex
	rm -f .tagversion test %ver% *~

re: cleanpdf ksp-physics.pdf
