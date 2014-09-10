ksp-physics.pdf: ksp-physics.tex
	latexmk -enable-write18 -pdf ksp-physics.tex
	latexmk -c ksp-physics.tex
	cp ksp-physics.pdf ksp-physics-$$(cat .tagversion | sed -e 's/[.]/-/g').pdf

clean:
	latexmk -c ksp-physics.tex
	rm -f *.pdf .tagversion test %ver%

re: clean ksp-physics.pdf
